# Exercício 10 — Aplicação do Padrão Circuit Breaker para Resiliência de APIs Externas

## Objetivo

Este exercício tem como objetivo aplicar o **padrão de design Circuit Breaker** para garantir a resiliência da aplicação **PictuRAS** quando integrada com serviços externos.
Os estudantes irão modelar e implementar uma solução que proteja a aplicação contra falhas e indisponibilidades de APIs externas, evitando degradação do serviço e melhorando a experiência do utilizador.

---

## Contexto

A aplicação **PictuRAS** foi expandida com uma funcionalidade avançada que aplica **filtros artísticos sofisticados** às imagens através de uma **API externa especializada**. Esta API oferece transformações visuais de alta qualidade que não estão disponíveis localmente.

### Características da integração:
- Os utilizadores podem selecionar filtros premium que dependem da API externa.
- A API externa é um serviço de terceiros (fora do controlo da equipa PictuRAS).
- A API pode ficar temporariamente indisponível devido a:
  - Manutenção programada
  - Sobrecarga de pedidos
  - Falhas de rede
  - Problemas no fornecedor do serviço
- Quando a API falha, os pedidos podem demorar muito tempo (timeouts) ou retornar erros.

### Problema:
Sem um mecanismo de proteção, a aplicação PictuRAS sofre de:
- **Cascading failures**: falhas na API externa propagam-se para toda a aplicação.
- **Resource exhaustion**: threads e conexões ficam bloqueadas aguardando respostas que nunca chegam.
- **Degradação da experiência**: utilizadores ficam sem resposta e a aplicação parece "travada".
- **Desperdício de recursos**: continuar a tentar chamar uma API que está em baixo é ineficiente.

### Solução: Circuit Breaker Pattern
O padrão Circuit Breaker atua como um disjuntor elétrico:
- Monitoriza chamadas à API externa.
- Quando detecta falhas excessivas, "abre o circuito" e impede novas chamadas.
- Retorna rapidamente respostas alternativas (fallback) sem sobrecarregar a API.
- Periodicamente tenta recuperar ("half-open") para verificar se a API voltou.

---

## Descrição da Tarefa

### 1. Compreender o Padrão Circuit Breaker

Estuda o padrão e identifica os **três estados principais**:

- **CLOSED (Fechado)**:
  - Estado normal de operação.
  - As chamadas à API são executadas normalmente.
  - Falhas são contabilizadas.
  - Se o número de falhas exceder um limiar, transita para OPEN.

- **OPEN (Aberto)**:
  - Circuito aberto — chamadas à API são bloqueadas.
  - Retorna imediatamente um resultado alternativo (fallback).
  - Após um timeout configurável, transita para HALF_OPEN.

- **HALF_OPEN (Semi-aberto)**:
  - Estado de teste — permite um número limitado de chamadas.
  - Se as chamadas tiverem sucesso, volta para CLOSED.
  - Se falharem, volta para OPEN.

### 2. Modelar a Solução com UML

Cria um **Diagrama de Classes UML** representando:

- **Interface `FilterAPI`**: representa a API externa de filtros.
- **Classe `CircuitBreaker`**: implementa a lógica do padrão.
  - Atributos:
    - `state`: estado atual (CLOSED, OPEN, HALF_OPEN)
    - `failureCount`: contador de falhas
    - `failureThreshold`: limiar de falhas para abrir o circuito
    - `timeout`: tempo para tentar recuperar
    - `lastFailureTime`: timestamp da última falha
  - Métodos:
    - `call(operation)`: executa operação com proteção
    - `recordSuccess()`: regista sucesso
    - `recordFailure()`: regista falha
    - `reset()`: reinicia o circuito
    - `transitionToOpen()`: abre o circuito
    - `transitionToHalfOpen()`: passa para semi-aberto
    - `transitionToClosed()`: fecha o circuito

- **Classe `ExternalFilterService`**: cliente que usa o CircuitBreaker.
- **Classe `FallbackStrategy`**: define estratégias de fallback quando a API está indisponível.

### 3. Definir Cenários de Uso

Modela o fluxo de interação usando **Diagramas de Sequência UML** para:

**Cenário 1: Operação Normal (Estado CLOSED)**
1. Utilizador solicita aplicação de filtro premium.
2. `ExternalFilterService` chama `CircuitBreaker.call()`.
3. CircuitBreaker está em estado CLOSED.
4. Chama a API externa.
5. API responde com sucesso.
6. Resultado é retornado ao utilizador.

**Cenário 2: Falhas Recorrentes (Transição CLOSED → OPEN)**
1. Utilizador solicita filtro.
2. CircuitBreaker tenta chamar API.
3. API falha (timeout ou erro).
4. CircuitBreaker incrementa `failureCount`.
5. Após várias falhas consecutivas (threshold atingido), CircuitBreaker transita para OPEN.
6. Próximas chamadas retornam fallback imediatamente sem chamar a API.

**Cenário 3: Recuperação (Transição OPEN → HALF_OPEN → CLOSED)**
1. Após timeout, CircuitBreaker transita para HALF_OPEN.
2. Permite uma chamada de teste à API.
3. API responde com sucesso.
4. CircuitBreaker transita para CLOSED.
5. Operação normal é restaurada.

### 4. Implementar um Protótipo

Desenvolve um **protótipo funcional** em **Java, Python, TypeScript ou C#** (à escolha).

O protótipo deve incluir:

- **Implementação completa do CircuitBreaker**:
  - Gestão de estados (CLOSED, OPEN, HALF_OPEN).
  - Contagem de falhas e sucessos.
  - Transições automáticas entre estados.
  - Timeout configurável.

- **Simulação da API externa**:
  - Método que simula processamento de filtro.
  - Capacidade de simular falhas e sucessos.
  - Delays variáveis para simular lentidão.

- **Estratégias de Fallback**:
  - Retornar imagem original sem filtro.
  - Aplicar filtro básico local (alternativa).
  - Retornar mensagem de erro amigável.
  - Guardar pedido para processamento posterior (queue).

- **Testes e Demonstração**:
  - Simular cenário de falha da API.
  - Demonstrar abertura do circuito.
  - Demonstrar recuperação automática.
  - Output de logs mostrando transições de estado.

### 5. Definir Parâmetros Configuráveis

A solução deve permitir configurar:
- `failureThreshold`: número de falhas antes de abrir (ex: 5)
- `timeout`: tempo até tentar recuperar (ex: 30 segundos)
- `successThreshold`: sucessos necessários em HALF_OPEN para fechar (ex: 2)
- `requestTimeout`: timeout individual por chamada à API (ex: 5 segundos)

---

## Resultado Esperado

O relatório e entrega devem incluir:

1. **Diagrama de Classes UML** representando a aplicação do padrão Circuit Breaker.

2. **Diagramas de Sequência UML** ilustrando os três cenários principais:
   - Operação normal
   - Detecção de falhas e abertura do circuito
   - Recuperação e fecho do circuito

3. **Diagrama de Estados UML** representando as transições entre CLOSED, OPEN e HALF_OPEN.

4. **Código-fonte do protótipo** funcional e bem comentado.

5. **Documentação técnica** incluindo:
   - Descrição da arquitetura da solução.
   - Justificação dos parâmetros de configuração escolhidos.
   - Estratégias de fallback implementadas.
   - Exemplos de output do protótipo (logs de execução).

6. **Análise e Reflexão Crítica** sobre:
   - Vantagens do Circuit Breaker para resiliência do sistema.
   - Limitações e trade-offs do padrão.
   - Comparação com alternativas (Retry, Timeout, Bulkhead).
   - Métricas importantes para monitorização (taxa de falhas, latência, estado do circuito).
   - Cenários onde o padrão é mais ou menos adequado.

---

## Orientações

- Mantém o design **simples e focado** no padrão Circuit Breaker.
- Usa **configuração externalizável** (ficheiro de propriedades ou variáveis de ambiente).
- Considera **thread-safety** se a aplicação for multi-threaded.
- Implementa **logging detalhado** para facilitar a observabilidade.
- Testa diferentes cenários de falha:
  - Timeouts
  - Erros HTTP (500, 503)
  - Exceções de rede
  - Respostas lentas
- O protótipo pode simular a API externa; o foco está na **implementação correta do padrão**.

---

## Resultados de Aprendizagem

Após este exercício, deverás ser capaz de:
- Aplicar o **padrão Circuit Breaker** em integrações com serviços externos.
- Implementar sistemas **resilientes a falhas** e **fault-tolerant**.
- Modelar **máquinas de estado** usando diagramas UML.
- Desenhar **estratégias de fallback** adequadas ao contexto.
- Configurar parâmetros de resiliência de forma consciente.
- Avaliar **trade-offs** entre disponibilidade e consistência.
- Compreender a importância da **observabilidade** em sistemas distribuídos.

---

## 📘 Exemplo Simplificado de Implementação

```java
// Enum para estados
enum CircuitState {
    CLOSED, OPEN, HALF_OPEN
}

// Classe Circuit Breaker
public class CircuitBreaker {
    private CircuitState state = CircuitState.CLOSED;
    private int failureCount = 0;
    private final int failureThreshold;
    private final long timeout;
    private long lastFailureTime = 0;

    public CircuitBreaker(int failureThreshold, long timeout) {
        this.failureThreshold = failureThreshold;
        this.timeout = timeout;
    }

    public <T> T call(Callable<T> operation, Supplier<T> fallback) throws Exception {
        // Verifica se deve transitar de OPEN para HALF_OPEN
        if (state == CircuitState.OPEN) {
            if (System.currentTimeMillis() - lastFailureTime >= timeout) {
                state = CircuitState.HALF_OPEN;
                System.out.println("Circuit transitioning to HALF_OPEN");
            } else {
                System.out.println("Circuit is OPEN - returning fallback");
                return fallback.get();
            }
        }

        try {
            T result = operation.call();
            recordSuccess();
            return result;
        } catch (Exception e) {
            recordFailure();
            System.out.println("Operation failed: " + e.getMessage());
            return fallback.get();
        }
    }

    private void recordSuccess() {
        failureCount = 0;
        if (state == CircuitState.HALF_OPEN) {
            state = CircuitState.CLOSED;
            System.out.println("Circuit CLOSED - service recovered");
        }
    }

    private void recordFailure() {
        failureCount++;
        lastFailureTime = System.currentTimeMillis();

        if (failureCount >= failureThreshold) {
            if (state != CircuitState.OPEN) {
                state = CircuitState.OPEN;
                System.out.println("Circuit OPEN - too many failures");
            }
        }
    }

    public CircuitState getState() {
        return state;
    }
}

// Serviço que usa o Circuit Breaker
public class ExternalFilterService {
    private CircuitBreaker circuitBreaker;
    private FilterAPI filterAPI;

    public ExternalFilterService(FilterAPI filterAPI) {
        this.filterAPI = filterAPI;
        this.circuitBreaker = new CircuitBreaker(3, 10000); // 3 falhas, 10s timeout
    }

    public Image applyPremiumFilter(Image image, String filterType) {
        try {
            return circuitBreaker.call(
                // Operação principal
                () -> filterAPI.applyFilter(image, filterType),
                // Fallback
                () -> {
                    System.out.println("Using fallback: returning original image");
                    return image; // Retorna imagem original
                }
            );
        } catch (Exception e) {
            System.err.println("Unexpected error: " + e.getMessage());
            return image;
        }
    }
}

// Interface da API externa
interface FilterAPI {
    Image applyFilter(Image image, String filterType) throws Exception;
}
```

### Exemplo de Uso:

```java
// Simula API externa com falhas
class UnreliableFilterAPI implements FilterAPI {
    private int callCount = 0;

    @Override
    public Image applyFilter(Image image, String filterType) throws Exception {
        callCount++;

        // Simula falhas nas primeiras 5 chamadas
        if (callCount <= 5) {
            throw new Exception("API temporarily unavailable");
        }

        // Simula sucesso após recuperação
        System.out.println("Filter applied successfully!");
        return image.applyFilter(filterType);
    }
}

// Teste
public class Main {
    public static void main(String[] args) throws InterruptedException {
        FilterAPI api = new UnreliableFilterAPI();
        ExternalFilterService service = new ExternalFilterService(api);
        Image testImage = new Image("test.jpg");

        // Tenta aplicar filtro várias vezes
        for (int i = 1; i <= 10; i++) {
            System.out.println("\n--- Attempt " + i + " ---");
            service.applyPremiumFilter(testImage, "vintage");
            Thread.sleep(2000); // Espera 2 segundos entre chamadas
        }
    }
}
```

### Output Esperado:
```
--- Attempt 1 ---
Operation failed: API temporarily unavailable
Using fallback: returning original image

--- Attempt 2 ---
Operation failed: API temporarily unavailable
Using fallback: returning original image

--- Attempt 3 ---
Operation failed: API temporarily unavailable
Circuit OPEN - too many failures
Using fallback: returning original image

--- Attempt 4 ---
Circuit is OPEN - returning fallback

... (após timeout) ...

--- Attempt 6 ---
Circuit transitioning to HALF_OPEN
Filter applied successfully!
Circuit CLOSED - service recovered
```

---

## 📚 Conceitos Relacionados e Extensões

### Padrões Complementares:
- **Retry Pattern**: tenta novamente após falha com backoff exponencial.
- **Timeout Pattern**: limita tempo de espera por resposta.
- **Bulkhead Pattern**: isola recursos para evitar que falhas se propaguem.
- **Cache-Aside Pattern**: usa cache como fallback quando serviço está indisponível.

### Métricas Importantes:
- Taxa de sucesso/falha das chamadas
- Tempo em cada estado (CLOSED, OPEN, HALF_OPEN)
- Latência das chamadas
- Número de fallbacks executados
- Tempo até recuperação

### Bibliotecas Existentes:
- **Java**: Resilience4j, Hystrix (deprecated)
- **Python**: pybreaker, tenacity
- **JavaScript/TypeScript**: opossum, cockatiel
- **.NET**: Polly

### Considerações de Design:
- Circuit Breaker deve ser **por instância de serviço** ou **global**?
- Como sincronizar estado em ambientes distribuídos?
- Onde persistir métricas para análise?
- Como notificar equipas quando circuito abre (alertas)?

---

## 📘 Cenários de Teste Sugeridos

### Teste 1: Comportamento Normal
- API externa funciona perfeitamente
- Todas as chamadas devem ter sucesso
- Circuit Breaker permanece em CLOSED

### Teste 2: Falha Temporária
- API falha por curto período
- Circuit Breaker abre após threshold
- Fallback é executado
- API recupera e circuit fecha

### Teste 3: Falha Prolongada
- API continua indisponível
- Circuit Breaker permanece em OPEN
- Fallback é sempre executado
- Não sobrecarrega a API

### Teste 4: Recuperação Instável
- API alterna entre sucesso e falha
- Circuit Breaker transita entre estados
- Sistema mantém estabilidade

### Teste 5: Alta Concorrência
- Múltiplas threads fazem chamadas simultâneas
- Circuit Breaker mantém consistência de estado
- Não há race conditions

---

## Recursos Adicionais

- [Martin Fowler — Circuit Breaker](https://martinfowler.com/bliki/CircuitBreaker.html)
- [Microsoft Azure — Circuit Breaker Pattern](https://docs.microsoft.com/en-us/azure/architecture/patterns/circuit-breaker)
- [Resilience4j Documentation](https://resilience4j.readme.io/)
- Livro: *Release It!* por Michael Nygard
- Livro: *Building Microservices* por Sam Newman
