# TEORIA
---
A rentabilidade do projeto deverá ser caracterizada por uma medida inequívoca e independente dos critérios contabilísticos adotados pela empresa.

### Fluxo de Caixa 

- Atividades de investimento
    - | Investimento em Imobilizado (Ativos fixos)
    - | Investimento em necessidades de fundo de maneio (Capital Circulante)
- Atividades Operacionais

- Atividades de Financiamento


Conta resultados líquidos do projeto: influenciado por aspetos
contabilísticos como as amortizações e provisões e pela estrutura de
financiamento do projeto

**Investimento em necessidades de fundo de maneio (Capital Circulante)**
> Montante necessário funcionamento do projeto de acordo com o seu ciclo
operacional.
Pretende garantir os meios financeiros necessários para efectuar pagamentos
em tempo, compensando também eventuais créditos concedidos a clientes

**Investimento em Imobilizado (Ativos fixos)**
> Bens intangíveis e tangíveis adquiridos para garantir o funcionamento do projeto.
*Imobilizado Incorpóreo* - integra os bens intangíveis, englobando, nomeadamente,
direitos e despesas de constituição, arranque e expansão, trespasses, propriedade
industrial e outros direitos, estudos e projetos entre outras.
*Imobilizado Corpóreo* - integra todos os bens imobilizados tangíveis, móveis ou imóveis,
que a empresa utiliza na sua actividade operacional, que não se destinem a ser
vendidos ou transformados, com carácter de permanência e vida útil superior a um ano
(ex. terrenos, edifícios e construções, máquinas, computadores, móveis, instalações,
ferramentas etc.)

**Amortização**
> É a perda de valor de um activo fixo, que se traduz na diminuição do seu valor contabilístico, por via da sua utilização ou desgaste. A amortização é um custo contabilístico que não implica uma saída de caixa, mas que deve ser considerado na determinação do resultado líquido do projecto. 

Cálculo do valor da amortização anual:
- Método linear
    - Amortização = Valor de aquisição / Vida útil  = Valor de aquisição * taxa de amortização
    - vida útil em anos


### Valor residual do investimento
> Valor que o activo imobilizado terá no final do seu ciclo de vida, ou seja, o valor que se espera obter com a sua venda no final do seu ciclo de vida. 

VR (imobilizado) = investimento acumulado - amortização acumulada (soma das amortizações)
VR (fundo de maneio) = 


### Cash-flow

O CF de um projeto é calculado pela soma do Cash-flow 
``` math
CFE = (Vendas - Custos - AR - EFF) (1 - t) + AR - EFF
```
```math
CFE = (Vendas - Custos) (1 - t) + AR * t + EFF * t
```

```math
RL (resultado líquido) = RAI - imposto a pagar = RAI - t * RAI = RAI (1 - t)
```
RAI = resultado antes de impostos

---
## Fórmulas

### 1. Fórmulas para Cálculo dos Fluxos de Caixa (Após Impostos)

**Amortização (Método das Quotas Constantes):**

```math
Amortizacao = Valor de aquisicao / Vida util  = Valor de aquisicao * taxa de amortizacao
```

**Lucro Antes de Impostos (LAI):**
```math
LAI = Vendas (receitas) - Custos - Amortizacao 
```
**Imposto sobre Lucros:**
```math
Imposto a pagar = taxa * LAI
```

**Lucro Depois de Impostos (LDI):**
```math
LDI = LAI - Imposto a pagar = LAI - t * LAI = LAI (1 - t)
```

**Fluxo de Caixa Operacional (FCO):**
```math
FCO = LDI + Amortizacao
```

*Adiciona-se a amortização porque não é uma saída efetiva de caixa.*

**Fluxo de Caixa Total por Ano:**
```math
FC_0=−Investimento Inicial−Fundo de Maneio
```

```math
FC_n = FCO+Valor Residual+Recuperacao do Fundo de Maneio
```

Resumo das Etapas para Resolver os Exercícios:

1. Calcular a amortização anual.
2. Determinar o LAI, imposto e LDI.
3. Calcular o FCO (LDI + Amortização).
4. Montar os fluxos de caixa totais (incluindo investimento inicial e fundo de maneio).
5. Aplicar as fórmulas de VAL, TIR e Payback.
6. Concluir sobre a viabilidade com base nos critérios.


### 2. Fórmulas para Análise de Viabilidade

**Valor Atual Líquido (VAL):**
```math
VAL = \sum_{t=0}^{t} \frac{FC_t}{(1 + r)^t}
```

Critério:
- Se VAL > 0, o projeto é viável.
- Se VAL < 0, o projeto não é viável.

**Taxa Interna de Retorno (TIR):**
```math
TIR = i \text{ tal que } VAL = 0
```

Critério:
- Se TIR > i (taxa de desconto), o projeto é viável.
- Se TIR < i, o projeto não é viável.

**Tempo de Recuperação (Payback):**
```math
Payback = \text{Tempo necessário para recuperar o investimento inicial}
```

```math
Payback Descontado=Ano onde o VAL acumulado se torna positivo.
```

### 3. Fórmulas Auxiliares
**Fator de Desconto (Valor Presente de um Fluxo Futuro):**
```math
VP = \frac{FC_t}{(1 + r)^t}
```

FC = Fluxo de Caixa no ano t

**Valor Presente de uma Anuidade (Fluxos Iguais):**
```math
VP = FC \times \left( \frac{1 - (1 + r)^{-n}}{r} \right)
```

**Valor Presente de um Valor Residual ou Único no Futuro:**
```math
VP = \frac{VR}{(1 + r)^n}
```

VR = Valor Residual