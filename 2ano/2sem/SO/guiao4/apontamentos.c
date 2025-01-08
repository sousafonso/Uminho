/**
 * 
 * IPC - Inter Process Communication
 * 
 * Os pipes anónimos permitem a comunicação entre processos pai e filho.
 * 
 * @def: Um pipe é um mecanismo de comunicação (em memória) entre processos que permite a comunicação entre processos, onde um processa e o outro lê
 * 
 * aka buffer produtor-consumidor. O consumidor bloqueia a letura até que o produtor escreva algo no buffer e o produtor bloqueia a escrita 
 * se não houver espaço no buffer.
 * 
 * O pipe é unidirecional, ou seja, só permite a comunicação num sentido (comunicação do tipo FIFO). Para comunicação bidirecional é necessário criar dois pipes.
 * 
 * @def: pipe(int pd[2]) -> cria um pipe com dois descritores de ficheiros, pd[0] para leitura e pd[1] para escrita
 * devolve 0 em caso de sucesso e -1 em caso de erro
 * 
 * @def: close(pd[0]) -> fecha o descritor de ficheiro de leitura quando eu só quero escrever
 * @def: close(pd[1]) -> fecha o descritor de ficheiro de escrita quando eu só quero ler
 * 
 * Na linha de comandos, o pipe é representado por |, que permite a comunicação entre processos
 * @def: ls | wc -l -> conta o número de linhas do output do comando ls
*/