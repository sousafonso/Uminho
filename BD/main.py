from populate_database import (
    # clear_tables,
    populate_clientes,
    # populate_departamentos,
    populate_detetives,
    # populate_casos,
    # populate_procedimentos,
    # populate_procedimento_caso,
    # populate_caso_detetive
)

if __name__ == "__main__":
    # clear_tables()
    populate_clientes("cliente.csv")
    populate_departamentos("departamento.csv")
    populate_detetives("detetive.csv")
    # populate_casos("caso.csv")
    # populate_procedimentos("procedimento.csv")
    # populate_procedimento_caso("procedimento_caso.csv")
    # populate_caso_detetive("caso_detetive.csv")
