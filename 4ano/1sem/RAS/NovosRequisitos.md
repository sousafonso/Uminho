| Requisito #1 | Tipo: Funcional | Use case #5 |
|--------------|----------------|----------------|
|Descrição | O sistema deve permitir que o utilizador adicione um projeto aos favoritos. |
|Racional | Facilitar o acesso rápido a projetos preferidos pelos utilizadores. |
|Origem | Necessidade identificada em entrevistas com utilizadores. |
|Prioridade | Should |
|Data de Criação | 2024-06-15 |

## 🗃️ Use Case: [Adicionar projeto aos favoritos]

| **Secção** | **Detalhes** |
| :--- | :--- |
| **Use Case ID** | UC-008 |
| **Nome** | Adicionar projeto aos favoritos |
| **Versão** | v1.1 |
| **Autor** | Afonso Sousa|
| **Data da Revisão** | 2025-10-29 |
| **Objetivo** | Permitir que o utilizador adicione um projeto aos seus favoritos para acesso rápido. |
| **Âmbito** | PictuRAS |
| **Ator Principal** | Utilizador autenticado |
| **Partes Interessadas & Interesses** | **Utilizador**: deseja aceder rapidamente a projetos favoritos. **Sistema**: deve permitir a gestão eficiente de projetos favoritos. |
| **Pré-condições** | O utilizador deve estar autenticado. O projeto deve conter uma ou mais imagens finalizadas ou em edição. |
| **Gatilho** | O utilizador seleciona o ícone “Adicionar aos Favoritos” (representado por uma estrela) ao lado do nome do projeto.|

---

### Fluxo Principal 

| Passo | Ação do Ator | Resposta do Sistema |
| :--- | :--- | :--- |
| 1 | O utilizador vê a lista dos seus projetos | Exibe a lista de projetos com a opção de adicionar aos favoritos. |
| 2 | O utilizador clica no ícone “Adicionar aos Favoritos” ao lado do projeto desejado. | O sistema adiciona o projeto à lista de favoritos e confirma a ação. |
| 3 | O utilizador pode visualizar a lista de projetos favoritos. | O sistema exibe a lista de projetos marcados como favoritos. |
| 4 | <p style= 'color:red'> O utilizador pode remover um projeto dos favoritos. ??? </p> | O sistema remove o projeto da lista de favoritos e confirma a ação. |


---

### Pós-condições

* O projeto é adicionado à lista de favoritos do utilizador.
* O utilizador pode aceder rapidamente aos projetos favoritos a partir da sua conta.