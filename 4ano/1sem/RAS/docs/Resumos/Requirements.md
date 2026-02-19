Este resumo fornece uma discussão abrangente sobre requisitos em engenharia de software, organizada em quatro tópicos principais: a definição de requisitos, requisitos funcionais, requisitos não-funcionais e requisitos de utilizador versus requisitos de sistema.

## Definição de Requisito

Um requisito é uma condição ou capacidade necessária por um utilizador para resolver um problema ou atingir um objetivo. Destaca a dupla perspetiva dos requisitos:

- **Necessidades do Utilizador:** O que o utilizador espera que o sistema faça;
- **Capacidades do Sistema:** Aquilo que o sistema deve ser capaz de fazer.

A norma IEEE 610.12-1990 define um requisito como:

- Uma condição ou capacidade para resolver um problema;
- Uma condição ou capacidade para satisfazer um contrato, norma ou especificação;
- Uma representação documentada do acima exposto.

A classificação divide os requisitos em categorias **funcionais** e **não-funcionais**. Os requisitos podem também ser "requisitos candidatos" identificados durante a elicitação mas ainda não aprovados para implementação.

## Requisitos Funcionais

Os requisitos funcionais descrevem funcionalidades específicas que o sistema deve desempenhar para satisfazer as necessidades do utilizador. Os aspetos principais incluem:

- **Independência da tecnologia:** Os requisitos funcionais não devem depender de escolhas específicas de design ou implementação;
- **Completude e coerência:** O conjunto de requisitos funcionais deve cobrir totalmente as necessidades do cliente sem contradições, o que é particularmente desafiante para sistemas complexos.

Podem também ser distinguidos entre:

- **Requisitos Explícitos:** Claramente declarados pelas partes interessadas;
- **Requisitos Implícitos:** Assumidos com base no conhecimento do domínio por parte dos engenheiros, mas não explicitamente solicitados pelos utilizadores.

Devem seguir os seguintes objetivos:
- **Clareza**: devem ser claros e compreensíveis para todos os stakeholders.
- **Consistência**: não devem haver conflitos entre os requisitos.
- **Completude**: devem cobrir todas as funcionalidades e restrições necessárias.
- **Verificabilidade**: devem ser testáveis e verificáveis.
- **Rastreabilidade**: deve ser possível rastrear a origem de cada requisito.

Exemplos:
- O sistema deve permitir que o utilizador faça login.
- O sistema deve permitir que o utilizador faça logout.
- O sistema deve permitir que o utilizador faça um pedido de um produto.

## Requisitos Não-Funcionais

Os requisitos não-funcionais é um conjunto de restrições impostas ao sistema no que toca ao desenvolvimento, o quão atrativo, seguro, eficiente e funcional ele deve ser. Estes requisitos **não alteram as funcionalidades principais** (requisitos funcionais) mas influenciam a usabilidade e o desempenho do sistema. Os pontos-chave incluem:

- **Propriedades Emergentes:** Características ao nível do sistema, como fiabilidade ou manutenibilidade, que não podem ser atribuídas a componentes individuais.
- **Requisitos Conflituantes:** Requisitos não funcionais afetam outros requisitos não funcionais. Isto é, quando se procura uma alta **performance** num sistema, isto afeta por exemplo a **manutenção** do sistema. Mas por exemplo, **adaptabilidade** já promove a **portabilidade**.

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

<!-- Os requisitos não-funcionais são ainda categorizados com base em diferentes frameworks:

- **1. Framework de Sommerville:**
	- **Requisitos de Produto:** Caracterizam aspetos do comportamento do próprio sistema (por exemplo, desempenho, fiabilidade, usabilidade);
	- **Requisitos Organizacionais:** Provêm de estratégias e procedimentos estabelecidos no contexto do processo de fabrico do sistema ou da organização cliente (por exemplo, normas de processo);
	- **Requisitos Externos:** Têm origem em fatores externos ao sistema e ao processo de desenvolvimento (por exemplo, restrições legais ou éticas).

- **2. Framework de Robertson:**
	- Os tipos incluem aparência, usabilidade, desempenho, necessidades operacionais, manutenção e suporte, segurança, fatores culturais/políticos e requisitos legais. -->

## Requisitos de Utilizador e de Sistema

Os requisitos de utilizador e de sistema são distinguidos com base no seu foco:

- **Requisitos de Utilizador:** Representam as necessidades do utilizador no domínio do problema, tipicamente expressos em linguagem natural para compreensão das partes interessadas;
- **Requisitos de Sistema:** Especificações técnicas detalhadas orientadas para o domínio da solução, auxiliando os engenheiros no design do sistema.

A análise eficaz de requisitos requer evitar decisões de design prematuras e garantir que o problema está bem caracterizado. Problemas mal formulados frequentemente levam a soluções inadequadas.

## Documento de Requisitos
Documento de Requisitos de Software (SRS - Software Requirements Specification) é um documento que descreve detalhadamente os requisitos funcionais e não-funcionais de um sistema de software a ser desenvolvido. O SRS serve como um contrato entre os stakeholders e a equipe de desenvolvimento, garantindo que todos tenham uma compreensão clara do que o sistema deve fazer. Uma template é:
