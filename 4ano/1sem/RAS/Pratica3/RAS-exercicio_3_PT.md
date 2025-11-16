# 🧩 Exercício 3: Refinar os Requisitos do Sistema para Clareza e Precisão

## 🎯 Objetivo
O objetivo deste exercício é **analisar e refinar os requisitos do sistema** criados no Exercício 2.  
Deverás focar em **eliminar ambiguidades** e garantir que todos os requisitos sejam **claros, mensuráveis, testáveis e inequívocos**.

---

## 🧠 Contexto
No Exercício 2, desenvolveste uma **Especificação de Requisitos do Sistema** mais completa para o caso de uso “Login do Utilizador”, incluindo requisitos **funcionais** e **não funcionais**.  
Agora, o próximo passo é **rever e melhorar** esses requisitos, tornando-os mais precisos e fáceis de verificar.

Requisitos pouco claros ou ambíguos conduzem frequentemente a **interpretações incorretas**, **erros de conceção** e **re-trabalho dispendioso**.  
Este exercício ajudará a identificar e corrigir essas situações logo nas fases iniciais do desenvolvimento.

---

## 🧾 Tarefas

### 1. **Rever os Requisitos Existentes**
- Analisa todos os requisitos do sistema criados no **Exercício 2**.  
- Identifica qualquer requisito que:
  - Use termos vagos (ex.: “rápido”, “amigável”, “seguro o suficiente”).  
  - Contenha várias ideias numa única frase (requisitos compostos).  
  - Não apresente critérios mensuráveis ou condições de aceitação claras.  
  - Possa ser interpretado de mais do que uma forma por programadores ou testadores.

---

### 2. **Reescrever os Requisitos Ambíguos**
- Reescreve cada requisito ambíguo para que seja **claro, específico e verificável**.  
- Utiliza termos mensuráveis sempre que possível.  
  - Exemplo:  
    - ❌ *“O sistema deve ser rápido.”*  
    - ✅ *“O sistema deve autenticar os utilizadores em até 2 segundos em condições normais de carga.”*

---

### 3. **Aplicar Regras de Qualidade aos Requisitos**
Ao reescrever, garante que cada requisito segue as seguintes **boas práticas**:

| Princípio | Descrição | Exemplo |
|------------|------------|----------|
| **Clareza** | O requisito é fácil de compreender e não ambíguo. | “O e-mail de redefinição de palavra-passe deve conter uma ligação de uso único válida por 15 minutos.” |
| **Testabilidade** | O requisito pode ser verificado por teste ou inspeção. | “O sistema deve permitir até 5 tentativas consecutivas de login antes de bloquear a conta.” |
| **Atomicidade** | Cada requisito expressa apenas uma ideia. | Evitar requisitos compostos como “O sistema deve iniciar sessão e redirecionar o utilizador para a página inicial.” |
| **Exequibilidade** | O requisito é tecnicamente possível dentro das restrições conhecidas. | Evitar afirmações irrealistas como “O sistema deve responder instantaneamente.” |
| **Consistência** | Não entra em contradição com outros requisitos ou com o contexto do sistema. | Garantir que todos os requisitos de login estão alinhados com o fluxo de autenticação. |

---

### 4. **Documentar as Reformulações**
- Para cada requisito modificado, documenta:
  - O **requisito original** (do Exercício 2).  
  - A **versão refinada** (após reescrita).  
  - Uma breve **justificação** que explique qual a ambiguidade resolvida.

Usa a tabela seguinte como exemplo:

| ID | Requisito Original | Requisito Refinado | Justificação da Alteração |
|----|--------------------|--------------------|----------------------------|
| SR-004 | O sistema deve fornecer um login seguro. | O sistema deve usar o protocolo HTTPS e encriptar todas as credenciais com SHA-256 durante o login. | Especifica o que “seguro” significa, indicando o protocolo e o tipo de encriptação. |
| SR-010 | O processo de login deve ser rápido. | O sistema deve concluir o processo de autenticação em até 2 segundos em condições normais de rede. | Substitui “rápido” por um critério de desempenho mensurável. |

---

## 📋 Entregáveis
1. Lista atualizada dos requisitos do sistema refinados.  
2. Tabela de comparação entre versões originais e melhoradas, com respetiva justificação.  
3. (Opcional) Breve reflexão (5–10 linhas) sobre os tipos de ambiguidades mais comuns e como foram resolvidas.

---

## 💡 Dicas
- Utiliza **linguagem mensurável** — números, limites de tempo, condições específicas, etc.  
- Evita adjetivos subjetivos como *fácil, eficiente, moderno, flexível, rápido*.  
- Pensa como um **tester**: o requisito pode ser verificado de forma objetiva?  
- Mantém **uma ideia por requisito**.  
- Revê cada requisito em grupo para verificar se pode ser mal interpretado.

---

## 📚 Objetivos de Aprendizagem
Ao concluir este exercício, deverás ser capaz de:
- Identificar afirmações ambíguas ou vagas em requisitos.  
- Reescrever requisitos para que sejam precisos, verificáveis e testáveis.  
- Aplicar boas práticas na redação de requisitos de elevada qualidade.  
- Compreender como a clareza dos requisitos suporta o design, os testes e a validação eficazes.

---
