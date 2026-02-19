# Requisitos e Arquiteturas de Software
---

Software engineering é uma disciplina composta por um conjunto de teorias, métodos e ferramentas necessárias para desenvolver sistemas de software. O principal objetivo é desenvolver software com qualidade, dentro do prazo e orçamento estabelecidos satisfazendo as necessidades dos clientes.

## 1. Engenharia de Requisitos
### 1.1 Definição
> Engenharia de Requisitos é a aplicação de metodologias e ferramentas para a definição, especificação, documentação, gestão, manutenção e verificação de requisitos de software. Todas as questões antes da implementação do sistema são tratadas aqui.

### 1.2 Objetivos
- Todos os requisitos relevantes são explicitamente conhecidos e compreensiveis no mais alto detalhe.
- Conformidade com os stakeholders.
- Os requisitos devem estar devidamente documentados e em conformidade com os formatos e templates estabelecidos.

### 1.3 Atividades
1. **Inicialização**: identificação das necessidades dos stakeholders e definição da arquitetura do sistema. No final, o engenheiro de requisitos deve ser capaz de descrever a visão do cliente e o retorno do investimento.
2. **Levantamento**: recolha de requisitos através de entrevistas, questionários, workshops, análise de documentos, observação direta, prototipagem. As técnicas de levantamento devem: identificar as fontes dos requisitos; ajudar as partes interessadas a descrever os requisitos corretamente.
3. **Análise e Modelagem**: análise dos requisitos recolhidos para identificar conflitos, inconsistências e lacunas. É habitual organizar os requisitos em grupos coerentes. Modelagem dos requisitos utilizando diagramas UML, casos de uso, diagramas de atividades, diagramas de classes.
4. **Negociação**: resolução de conflitos entre requisitos e partes interessadas. Utilização de técnicas de negociação, mediação, priorização dos requisitos.
5. **Documentação**: criação de documentos de requisitos claros e compreensíveis. Utilização de templates, padrões de escrita, linguagem natural, diagramas. O documento está orgamizado em requisitos de utilizador e requisitos do sistema.
6. **Validação**: verificação dos requisitos para garantir que estão corretos, completos e em conformidade com as necessidades dos stakeholders. Utilização de revisões, inspeções, prototipagem, testes de aceitação.
7. **Gestão de Requisitos**: acompanhamento das mudanças nos requisitos ao longo do ciclo de vida do projeto. Utilização de ferramentas de gestão de requisitos, rastreabilidade dos requisitos, controle de versões.

### 1.4 Desafios
- A engenharia de requisitos tenta caracterizar com rigor o problema.
- As outras atividades do processo definem e refinam uma solução.
- Esta distinção existe porque as atividades de engenharia de requisitos são inerentemente difíceis.
- São comuns problemas de comunicação entre engenheiros de requisitos e utilizadores.
- Os utilizadores têm dificuldade em expressar as suas necessidades de forma percetível e precisa.
- Muitas vezes, os utilizadores só têm uma ideia vaga do que realmente querem.
- Os requisitos mudam frequentemente durante o desenvolvimento.

### 1.5 Metodologias
- **RUP**: Rational Unified Process.
- **SCRUM**: Scrum.
- **XP**: Extreme Programming.
- **Agile**: Agile.
- **Waterfall**: Waterfall.

**Waterfall**
- Processo linear e sequencial. Não tem como voltar a fases anteriores ou não é suposto.
- Cada fase deve ser concluída antes de passar para a próxima.
- Fases: 1. Análise, 2. Design, 3. Implementação, 4. Testes, 5. Manutenção.
- Vantagens: Simplicidade, fácil de entender e gerir, documentação clara.
- Desvantagens: Rígido, difícil de acomodar mudanças, feedback tardio.

## 2. Requisitos
### 2.1 Definição
> Requisitos são as condições/restrições ou capacidades que um sistema deve possuir para satisfazer as necessidades dos utilizadores ou outras partes interessadas. Ou seja, é algo que alguém deseja que o sistema faça ou uma característica que ele deve ter.

Os requisitos podem ser classificados em:
- Funcionais
- Não-funcionais

Devem seguir os seguintes objetivos:
- **Clareza**: devem ser claros e compreensíveis para todos os stakeholders.
- **Consistência**: não devem haver conflitos entre os requisitos.
- **Completude**: devem cobrir todas as funcionalidades e restrições necessárias.
- **Verificabilidade**: devem ser testáveis e verificáveis.
- **Rastreabilidade**: deve ser possível rastrear a origem de cada requisito.

### 2.2 Funcionais
> Funcionalidades que devem estar disponíveis para o utilizador. Respostas que o sistema deve fornecer como estimulo às ações do utilizador.

Exemplos:
- O sistema deve permitir que o utilizador faça login.
- O sistema deve permitir que o utilizador faça logout.
- O sistema deve permitir que o utilizador faça um pedido de um produto.

### 2.3 Não-funcionais
- **Restrições** ou **definições técnicas** que o sistema deve possuir.
- Definem a estética, velocidade e o quão credível é o sistema.
- Estes requisitos não devem alterar a essência das funcionalidades do sistema.
- São requisitos que afetam o sistema como um todo e não apenas algumas partes do sistema.
- São essênciais para definir a arquitectura do sistema.
- Requisitos não funcionais afetam outros requisitos não funcionais. Isto é, quando se procura uma alta **performance** num sistema, isto afeta por exemplo a **manutenção** do sistema. Mas por exemplo, **adaptabilidade** já promove a **portabilidade**.

Exemplos:
- O sistema deve ser rápido.
- O sistema deve ser seguro.
- O sistema deve ser fácil de usar.
- O sistema deve ser fácil de manter.
- O sistema deve ser fácil de implementar.
- O sistema deve ser desenvolvido em Java.

Existem 8 tipos de requisitos não funcionais:
- **Performance**: velocidade, real-time, storage capacity, execution correction.
- **Segurança**: acesso, confidencialidade, proteção e integridade dos dados.
- **Usabilidade**: facilidade de uso e interface do sistema. Se é intuitiva e amigável. Exemplos:
    - O produto deve ser fácil de utilizar para analfabetos.
    - Deve ser intuitivo para crianças de 5 anos.
    - Deve ser fácil de utilizar para pessoas com deficiência visual.
- **Operacionalidade**: características que o sistema deve ter para funcionar corretamente num determinado ambiente.
- **Manutenção e Suporte**: atributos que permitem a reparação ou melhoria e novas funcionalidade para serem adicionadas. Exemplos:
    - O código deve estar devidamente documentado (com comentários).
    - O produto deve estar pronto para ser traduzido.
- **Aparencia**: estética e design do sistema.
- **Cultural e Político**: atributos que permitem a adaptação do sistema aos hábitos e cultura dos utilizadores.
- **Legal**: atributos que permitem a conformidade do sistema com as leis e regulamentos aplicáveis.

### 2.4 Requisitos do Utilizador
1. Funcionalidade que o sistema deve fornecer ao **utilizador**.
2. Restrição que é aplicada a uma operação do sistema.

São requisitos relacionados com o problema em si. Requisitos que devem responder diretamente às necessidades do utilizador.

### 2.5 Requisitos do Sistema
1. Especificação + detalhada do requisito.
2. Requisitos relacionados à solução => deve ajudar os engenheiros no design e construção da solução.
3. Têm termos + técnicos comparativamente aos outros.

### 2.6 Documentação de Requisitos - Estrutura Genérica
**Desencadeadores do Projeto**

1. Finalidade do sistema
2. Cliente, clientes, partes interessadas
3. Utilizadores do sistema

**Restrições do Projeto**
4. Restrições obrigatórias
5. Taxonomia e definições
6. Factos e pressupostos

**Requisitos Funcionais**
7. Âmbito do trabalho
8. Âmbito do sistema
9. Requisitos funcionais e de dados

**Requisitos Não Funcionais**
10. Aspeto
11. Usabilidade
12. Desempenho
13. Operacional
14. Manutenção e suporte
15. Segurança
16. Cultural e político
17. Legal

**Questões do Projeto**
18. Questões em aberto
19. Soluções imediatas
20. Novos problemas
21. Tarefas
22. Migração para o novo sistema
23. Riscos
24. Custos
25. Manual do utilizador
26. Sala de espera (requisitos para versões futuras)
27. Ideias para soluções
