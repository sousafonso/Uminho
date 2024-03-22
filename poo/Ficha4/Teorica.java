/**
 * 
 * @brief Streams
 * Uma stream é uma sequência de elementos que suporta operações sequenciais e paralelas.
 * A nível abstrato posso pensar que é uma coleção de elementos.
 * 
 * ITERADORES INTERNOS
 * 
 * @brief Consulta
 * allMatch (condição) - verifica se todos os elementos do stream satisfazem a condição
 * anyMatch (condição) - verifica se algum dos elementos do stream satisfaz a condição
 * noneMatch (condição) - verifica se nenhum dos elementos do stream satisfaz a condição
 * 
 * @brief Folds
 * count() - conta o número de elementos do stream
 * collect(Collectors.toList()) - transforma o stream numa lista
 * reduce(E, operação binária) - soma todos os elementos do stream
 * toArray() - transforma o stream num array
 * 
 * @brief Transformações
 * map(f) - aplica a função f a cada elemento do stream
 * filter(condição) - filtra os elementos do stream que satisfazem a condição
 */
