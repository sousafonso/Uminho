# Use Case: [Carregar Imagem]

| **Section** | **Details** |
|-------------|-------------|
| **Use Case ID** | UC-001 |
| **Name** | Carregar Imagem |
| **Version** | v1.0 |
| **Author** | Vicente Martins |
| **Date** | 2025-08-01 |
| **Goal** | Permitir que o utilizador carregue uma imagem no sistema|
| **Scope** | PictuRAS |
| **Primary Actor** | Utilizador |
| **Stakeholders & Interests** | **Utilizador**: quer carregar imagens e iniciar edição<br> **Administrador**: quer garantir que apenas arquivos válidos sejam aceites e que o sistema seja seguro.<br> **Sistema**: deve processar a imagem |
| **Preconditions** | Utilizador possui um arquivo de imagem válido. |
| **Trigger** | Utilizador clica no botão “Carregar Imagem”. |

---

## Main Flow

| **Step** | **Actor Action** | **System Response** |
|----------|------------------|----------------------|
| 1 | Seleciona “Carregar Imagem” na interface. | Exibe diálogo de seleção de arquivo. |
| 2 | Escolhe a imagem  que deseja | Valida formato e tamanho do arquivo. |
| 3 | ... | Carrega imagem para a área de edição. |
| 4 | ... | Exibe imagem carregada. |

*→ This is the “happy path,” the ideal flow where everything works correctly.*

---

## Alternate Flows

| **Flow** | **Description** |
|----------|------------------|
| AF1 – [Name] | *Variation from the main flow (e.g., login with Google)* |
| AF2 – [Name] | *Another variation (e.g., “Remember Me” option)* |

*→ Covers optional flows or variations where the goal is still achieved.*

---

## Exceptions

| **Condition** | **System Behavior** |
|---------------|----------------------|
| Formato inválido | Exibir mensagem de erro “Formato não suportado” |
| Falha de upload | Informar utilizador sobre falha de upload |

*→ Defines what happens when things go wrong (errors, failures, unavailability).*

---

## Postconditions

| **Type** | **Outcome** |
|----------|-------------|
| Success Guarantee | Imagem carregada disponível na área de edição |
| Minimal Guarantee | Sistema permanece estável, a imagem não é carregada e o usuário pode tentar novamente. |

---

## Business Rules & Constraints

| **Rule** |
|----------|
| Apenas formatos JPG e PNG são suportados. |

---

## Assumptions

| **Assumption** |
|----------------|
| Utilizador tem conexão de internet estável. |
| Sistema tem espaço suficiente para o upload da imagem |

---

## Open Issues

| **Question** |
|--------------|
| Será necessário suportar outros formatos de imagem? |
| O sistema deve permitir múltiplos uploads simultâneos? | ```