
r0  S -> instrucoes $
r1  instrucoes -> instrucao instrucoes
r2  instrucoes -> instrucao instrucoes 
r2.5                | ε
r3  instrucao -> PUSH valor
r4              |POP
r5              |SWAP
r6              |OP operador

r7  valor -> INT 
r8  operador -> + | - | * | /

> LOOKAHEAD (r1) = {PUSH, POP, SWAP, OP}
LOOKAHEAD (r8) = {INT}
LOOKAHEAD (r2) = {PUSH, POP, SWAP, OP}
First (instrucao) = {PUSH, POP, SWAP, OP}

> LOOKAHEAD (r2) = {PUSH, POP, SWAP, OP}
LOOKAHEAD (r2.5) = {$}


