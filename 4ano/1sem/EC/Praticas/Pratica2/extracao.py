import os
import sys
import logging
from typing import Optional, Sequence

import oracledb
import pymongo

logging.basicConfig(level=logging.INFO, format='%(asctime)s %(levelname)s: %(message)s')
logger = logging.getLogger(__name__)


def export_table(cursor: oracledb.Cursor, mongo_db: pymongo.database.Database, table_name: str,
                 collection_name: str, pk_columns: Optional[Sequence[str]] = None) -> int:
    """Export all rows from an Oracle table into a MongoDB collection.

    - Uses cursor.description to build documents.
    - Maps primary key column(s) to the MongoDB `_id` field. If multiple PK columns are provided,
      `_id` will be a string joining their values with an underscore.
    - Uses replace_one with upsert to avoid duplicates.

    Returns the number of rows processed.
    """
    logger.info('Exporting table %s -> collection %s (pk=%s)', table_name, collection_name, pk_columns)
    cursor.execute(f'SELECT * FROM {table_name}')
    cols = [col[0] for col in cursor.description]
    coll = mongo_db[collection_name]
    count = 0
    for row in cursor:
        doc = {cols[i]: row[i] for i in range(len(cols))}

        # Build _id from PK columns if supplied and present in the row
        if pk_columns:
            try:
                pk_values = [doc[col] for col in pk_columns]
            except KeyError:
                # Fallback: try uppercase keys (Oracle typically returns uppercase)
                pk_values = [doc.get(col.upper()) for col in pk_columns]

            if None in pk_values:
                # If any PK value is None, create a composite string including 'null'
                pk_str = '_'.join([str(v) for v in pk_values])
            else:
                pk_str = '_'.join([str(v) for v in pk_values])
            doc['_id'] = pk_str
        else:
            # If no PK specified, try to use a single column named like ID_* if present
            candidate = next((c for c in cols if c.startswith('ID_')), None)
            if candidate:
                doc['_id'] = doc[candidate]

        # Optionally convert date/time types if needed (oracledb usually returns datetime)

        # Perform upsert to avoid inserting duplicates
        if '_id' in doc:
            _id = doc['_id']
            # Ensure _id not duplicated inside doc
            # Remove any duplicate key (if candidate id also present)
            try:
                coll.replace_one({'_id': _id}, doc, upsert=True)
            except Exception:
                logger.exception('Failed upsert for %s id=%s', table_name, _id)
        else:
            # No _id available: insert a new document
            try:
                coll.insert_one(doc)
            except pymongo.errors.DuplicateKeyError:
                logger.warning('Duplicate when inserting into %s; skipping', collection_name)
            except Exception:
                logger.exception('Failed insert for %s', table_name)

        count += 1

    logger.info('Finished exporting %d rows from table %s', count, table_name)
    return count


def main():
    # Configuration - keep simple; could be replaced with env vars
    oracle_user = os.getenv('ORACLE_USER', 'afonso')
    oracle_password = os.getenv('ORACLE_PASSWORD', 'afonso')
    oracle_dsn = os.getenv('ORACLE_DSN', 'localhost/orclpdb1')

    mongo_uri = os.getenv('MONGO_URI', 'mongodb://localhost:27017')
    mongo_db_name = os.getenv('MONGO_DB', 'restaurante_db')

    # Connect to Oracle
    try:
        conn = oracledb.connect(user=oracle_user, password=oracle_password, dsn=oracle_dsn)
    except Exception:
        logger.exception('Could not connect to Oracle DB')
        sys.exit(1)

    cursor = conn.cursor()

    # Connect to MongoDB
    try:
        mongo_client = pymongo.MongoClient(mongo_uri)
        mongo_db = mongo_client[mongo_db_name]
    except Exception:
        logger.exception('Could not connect to MongoDB')
        cursor.close()
        conn.close()
        sys.exit(1)

    # Define the tables to export and their target collection names + primary key columns
    tasks = [
        ("RESTAURANTE", "restaurantes", ["ID_RESTAURANTE"]),
        ("CLIENTE", "clientes", ["ID_CLIENTE"]),
        ("ENTREGADOR", "entregadores", ["ID_ENTREGADOR"]),
        ("CATEGORIA", "categorias", ["ID_CATEGORIA"]),
        ("PRATO", "pratos", ["ID_PRATO"]),
        ("PEDIDO", "pedidos", ["ID_PEDIDO"]),
        # ITEM_PEDIDO has composite primary key (ID_PEDIDO, ID_PRATO)
        ("ITEM_PEDIDO", "itens_pedido", ["ID_PEDIDO", "ID_PRATO"]),
    ]

    total = 0
    try:
        for table, coll_name, pk in tasks:
            processed = export_table(cursor, mongo_db, table, coll_name, pk_columns=pk)
            total += processed
    finally:
        try:
            cursor.close()
            conn.close()
        except Exception:
            logger.exception('Error closing Oracle connection')

    logger.info('All done. Total rows processed: %d', total)


if __name__ == '__main__':
    main()
