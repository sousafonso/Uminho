/**
 * @file teorica.c
 * 
 * @def Dup
 * 
 * @brief A função dup cria uma cópia do descritor de arquivo antigo e retorna o novo descritor de arquivo.
 * 
 * dup(int oldfd);
 * 
 * @param oldfd - O descritor de arquivo antigo. É criada uma cópia deste descritor de arquivo.
 * 
 * É escolhido o descritor de arquivo mais baixo disponível para o novo descritor de arquivo.
 * 
 * @return Retorna o novo descritor de arquivo.
 * 
 * @def Dup2
 * 
 * dup2(int oldfd, int newfd);
 * 
 * @brief A função dup2 cria uma copia do descritor oldfd no descritor newfd.
 * 
 * @param oldfd - O descritor de arquivo antigo.
 * @param newfd - O descritor de arquivo novo.
 * 
 * Se o descritor de arquivo newfd já estiver aberto, ele é fechado antes de ser reutilizado.
 * 
 * @return Retorna o valor de newfd.
*/