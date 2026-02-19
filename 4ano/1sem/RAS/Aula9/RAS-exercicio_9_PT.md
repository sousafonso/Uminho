# Exercício 9 — Implementação do Padrão Observer para Novos Filtros

## Objetivo

Este exercício tem como objetivo aplicar o padrão de design Observer num contexto real da aplicação PictuRAS.
Os estudantes irão implementar um sistema de notificações para informar os utilizadores quando novos filtros de processamento são adicionados ao sistema.

---

## Contexto

A aplicação PictuRAS está em constante evolução, com novos filtros de processamento de imagem e vídeo a serem desenvolvidos regularmente pela equipa de engenharia. Para manter os utilizadores envolvidos:

- O sistema deve permitir o registo dinâmico de novos filtros sem reiniciar a aplicação.
- Os utilizadores (ou sistemas clientes) devem ser notificados imediatamente quando um novo filtro fica disponível.
- Diferentes tipos de utilizadores podem estar interessados em diferentes categorias de filtros (ex: filtros de cor, filtros de distorção, filtros AI).

O padrão Observer é ideal para este cenário pois permite:
- Desacoplar o registo de filtros da lógica de notificação.
- Notificar múltiplos interessados (UI, sistema de emails, utilizadores) automaticamente.
- Seguir o princípio Open/Closed (aberto para extensão, fechado para modificação).

---

## Descrição da Tarefa

1. **Análise do Padrão Observer**
   - Identifica os elementos principais do padrão neste contexto:
     - **Subject**: O gestor de filtros (FilterManager/Registry).
     - **Observer**: Quem deseja saber sobre novos filtros.

2. **Design da Solução**
   - Define as interfaces necessárias:
     ```java
     public interface FilterAvailabilityObserver {
         void onNewFilterAvailable(String filterName, String description, String category);
     }
     ```
   - Identifica as classes concretas:
     - `FilterRegistry` (Subject): Mantém a lista de filtros e observadores.
     - `UserDashboard` (Observer): Atualiza a UI quando sai um filtro novo.
     - `MarketingNotifier` (Observer): Envia emails promocionais sobre o novo filtro.

3. **Implementação do Protótipo**
   - Implementa o mecanismo de registo de observadores.
   - Implementa a lógica de adição de filtros que dispara a notificação.
   - Simula múltiplos observadores recebendo a notificação.

4. **Documentação**
   - Diagrama de classes UML.
   - Diagrama de sequência mostrando o fluxo: `addFilter()` -> `notifyObservers()` -> `update()`.

---

## Resultado Esperado

O protótipo deve incluir:

1. **Classes e Interfaces**
   - Interface `FilterAvailabilityObserver`.
   - Classe `FilterRegistry` (Subject).
   - Pelo menos duas implementações de observadores (ex: `ConsoleLogger`, `NotificationService`).

2. **Funcionalidades Mínimas**
   - Adicionar um novo filtro ao registo.
   - O registo deve notificar automaticamente todos os subscritores.
   - Capacidade de remover um subscritor (unsubscribe).

3. **Documentação**
   - Diagramas e justificação das escolhas.

---

## 📘 Exemplo de Implementação Base

```java
// Interface Observer
public interface FilterAvailabilityObserver {
    void onNewFilterAvailable(String filterName, String description);
}

// Classe Subject (Observable)
public class FilterRegistry {
    private List<FilterAvailabilityObserver> observers = new ArrayList<>();
    private List<String> availableFilters = new ArrayList<>();

    public void subscribe(FilterAvailabilityObserver observer) {
        observers.add(observer);
    }

    public void unsubscribe(FilterAvailabilityObserver observer) {
        observers.remove(observer);
    }

    public void registerNewFilter(String name, String description) {
        availableFilters.add(name);
        notifyObservers(name, description);
    }

    private void notifyObservers(String name, String description) {
        for (FilterAvailabilityObserver observer : observers) {
            observer.onNewFilterAvailable(name, description);
        }
    }
}

// Exemplo de Concrete Observer
public class MarketingNotifier implements FilterAvailabilityObserver {
    @Override
    public void onNewFilterAvailable(String filterName, String description) {
        System.out.println("[MARKETING] Novo filtro lançado! Enviar campanha sobre: " + filterName);
    }
}
```

**Desafios Extra:**
- Implementar filtragem de eventos (ex: notificar apenas se o filtro for da categoria "Premium").
- Garantir que a notificação é assíncrona para não bloquear o registo do filtro.
