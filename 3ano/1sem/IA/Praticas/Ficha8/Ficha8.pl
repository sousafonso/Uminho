% Exercício 1 - Predicados em Prolog

% i. Quais os alunos que não estão inscritos em qualquer disciplina
aluno_nao_inscrito(Aluno) :-
    aluno(AlunoID, Aluno, _),
    \+ inscrito(AlunoID, _).

% ii. Quais os alunos que não estão inscritos em qualquer disciplina, assumindo que uma disciplina inexistente não é válida
aluno_nao_inscrito_validado(Aluno) :-
    aluno(AlunoID, Aluno, _),
    (\+ inscrito(AlunoID, _); inscrito(AlunoID, DisciplinaID), \+ disciplina(DisciplinaID, _, _, _)).

% iii. Qual a média de um determinado aluno
media_aluno(AlunoID, Media) :-
    findall(Nota, nota(AlunoID, _, Nota), Notas),
    length(Notas, Total),
    Total > 0,
    sum_list(Notas, Soma),
    Media is Soma / Total.

% iv. Quais os alunos cuja média é acima da média geral
todos_alunos_medias(Medias) :-
    findall(Media, (aluno(ID, _, _), media_aluno(ID, Media)), Medias).

media_geral(MediaGeral) :-
    todos_alunos_medias(Medias),
    sum_list(Medias, Soma),
    length(Medias, Total),
    MediaGeral is Soma / Total.

aluno_acima_da_media(Aluno) :-
    aluno(AlunoID, Aluno, _),
    media_aluno(AlunoID, Media),
    media_geral(MediaGeral),
    Media > MediaGeral.

% v. Quais os nomes dos alunos que copiaram
copiaram(Aluno1, Aluno2) :-
    copia(Aluno1, Aluno2).

% vi. Quais os alunos que copiaram (direta ou indiretamente) por um dado aluno
copiaram_indiretamente(Aluno, Copiador) :-
    copia(Aluno, Copiador).
copiaram_indiretamente(Aluno, Copiador) :-
    copia(Aluno, Outro),
    copiaram_indiretamente(Outro, Copiador).

% vii. mapToNome - converter uma lista de números de alunos numa lista de nomes
mapToNome([], []).
mapToNome([ID|IDs], [Nome|Nomes]) :-
    aluno(ID, Nome, _),
    mapToNome(IDs, Nomes).
mapToNome([_|IDs], Nomes) :-
    mapToNome(IDs, Nomes).

% Exercício 2 - Predicados em Prolog

% i) Quantos leitores do sexo feminino existem
quantidade_leitoras(Quantidade) :-
    findall(Leitora, (leitor(_, Leitora, f, _)), ListaLeitoras),
    length(ListaLeitoras, Quantidade).

% ii) Quais os livros que foram requisitados por leitores, mas que não se encontram associados a nenhuma biblioteca
livros_requisitados_sem_biblioteca(Livro) :-
    requisicao(_, Livro, _),
    \+ livros(Livro, _, _).

% iii) Indique quais os livros e respetivos leitores que requisitaram em bibliotecas situadas em Braga
livros_em_braga(Livro, Leitor) :-
    requisicao(Leitor, Livro, Biblioteca),
    biblioteca(Biblioteca, _, braga).

% iv) Quais os livros que não tiveram nenhuma requisição
livros_sem_requisicao(Livro) :-
    livros(Livro, _, _),
    \+ requisicao(_, Livro, _).

% v) Lista de livros e respetiva data de requisição, pedidos em 2022
livros_requisitados_2022(Livro, Data) :-
    requisicao(_, Livro, _, Data),
    Data = data(2022, _, _).

% vi) Leitores que requisitaram livros no Verão (Julho a Setembro)
leitores_verao(Leitor) :-
    requisicao(Leitor, _, _, data(_, Mes, _)),
    Mes >= 7,
    Mes =< 9.

% vii) Leitores que entregaram livros depois da data limite de 15 dias
leitores_atrasados(Leitor) :-
    requisicao(Leitor, _, _, data(Ano, Mes, Dia)),
    devolucao(Leitor, _, data(AnoD, MesD, DiaD)),
    date_difference(data(Ano, Mes, Dia), data(AnoD, MesD, DiaD), Diferenca),
    Diferenca > 15.

% Predicado auxiliar para calcular a diferença entre datas
date_difference(data(Ano, Mes, Dia), data(AnoD, MesD, DiaD), Diferenca) :-
    date_time_stamp(date(Ano, Mes, Dia), TimeStamp1),
    date_time_stamp(date(AnoD, MesD, DiaD), TimeStamp2),
    Diferenca is round((TimeStamp2 - TimeStamp1) / 86400).
