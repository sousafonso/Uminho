# TEORIA

ls -l output:

\- | rw- | rw- | r-- | 1 | user | 790 | date | filetxt

file type | owner | group | others | .... | owner | file size | last modification | filename

---

## umask

- ### files
666 <=> rw-

- ### diretorias
777 <=> rwx

default = 0002

---

## Discritionary Access Control (DAC)
- mais comum em sistemas UNIX
- owner define permissões

## Mandatory Access Control (MAC)
- administrador ou sistema definem permissões

## Role Based Access Control (RBAC)
- permissões com base no role