# Boilerplate Code for Circuit Breaker Exercise

This document contains the starting code for the Circuit Breaker exercise. You should create the following files in your Java project.

## 1. CircuitState.java
Enum representing the possible states of the Circuit Breaker.

```java
package com.picturas.resilience;

public enum CircuitState {
    CLOSED,
    OPEN,
    HALF_OPEN
}
```

## 2. Image.java
A simple placeholder class representing an image.

```java
package com.picturas.model;

public class Image {
    private String name;
    private String content;

    public Image(String name) {
        this.name = name;
        this.content = "Original Content";
    }

    public String getName() {
        return name;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public String toString() {
        return "Image{name='" + name + "', content='" + content + "'}";
    }
}
```

## 3. FilterAPI.java
Interface for the external filter service.

```java
package com.picturas.api;

import com.picturas.model.Image;

public interface FilterAPI {
    /**
     * Applies a filter to an image.
     * @param image The image to process.
     * @param filterType The type of filter to apply.
     * @return The processed image.
     * @throws Exception If the external service fails.
     */
    Image applyFilter(Image image, String filterType) throws Exception;
}
```

## 4. CircuitBreaker.java
The core class where you will implement the Circuit Breaker pattern logic.

```java
package com.picturas.resilience;

import java.util.concurrent.Callable;
import java.util.function.Supplier;

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

    /**
     * Executes an operation with Circuit Breaker protection.
     * 
     * @param operation The operation to execute (e.g., calling the external API).
     * @param fallback The fallback strategy to use if the operation fails or circuit is open.
     * @return The result of the operation or the fallback.
     */
    public <T> T call(Callable<T> operation, Supplier<T> fallback) {
        // TODO: Implement the Circuit Breaker logic here
        // 1. Check if the circuit is OPEN.
        //    - If OPEN, check if timeout has expired to transition to HALF_OPEN.
        //    - If timeout has not expired, return fallback immediately.
        
        // 2. If CLOSED or HALF_OPEN, try to execute the operation.
        //    - If successful, record success and return result.
        //    - If failed, record failure and return fallback.
        
        return null; // Placeholder
    }

    private void recordSuccess() {
        // TODO: Implement success logic
        // - Reset failure count.
        // - If state is HALF_OPEN, transition to CLOSED.
    }

    private void recordFailure() {
        // TODO: Implement failure logic
        // - Increment failure count.
        // - Update lastFailureTime.
        // - If failure threshold reached, transition to OPEN.
    }

    public CircuitState getState() {
        return state;
    }
}
```

## 5. ExternalFilterService.java
The service that uses the Circuit Breaker to call the external API.

```java
package com.picturas.service;

import com.picturas.api.FilterAPI;
import com.picturas.model.Image;
import com.picturas.resilience.CircuitBreaker;

public class ExternalFilterService {
    private final CircuitBreaker circuitBreaker;
    private final FilterAPI filterAPI;

    public ExternalFilterService(FilterAPI filterAPI) {
        this.filterAPI = filterAPI;
        // Initialize Circuit Breaker with 3 failures threshold and 5000ms timeout
        this.circuitBreaker = new CircuitBreaker(3, 5000);
    }

    public Image applyPremiumFilter(Image image, String filterType) {
        // TODO: Use the circuitBreaker.call() method to protect the API call.
        // Define the operation (lambda) and the fallback (lambda).
        
        return null; // Placeholder
    }
}
```

## 6. Main.java
A test class to simulate scenarios.

```java
package com.picturas;

import com.picturas.api.FilterAPI;
import com.picturas.model.Image;
import com.picturas.service.ExternalFilterService;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        // Mocking the API to simulate failures
        FilterAPI mockApi = new FilterAPI() {
            private int attempts = 0;
            @Override
            public Image applyFilter(Image image, String filterType) throws Exception {
                attempts++;
                // Simulate failure for the first 5 attempts
                if (attempts <= 5) {
                    throw new Exception("External API Service Unavailable");
                }
                image.setContent(image.getContent() + " + " + filterType + " Filter");
                return image;
            }
        };

        ExternalFilterService service = new ExternalFilterService(mockApi);
        Image myPhoto = new Image("vacation.jpg");

        System.out.println("Starting Circuit Breaker Simulation...");

        for (int i = 1; i <= 10; i++) {
            System.out.println("\n--- Request " + i + " ---");
            Image result = service.applyPremiumFilter(myPhoto, "Vintage");
            System.out.println("Result: " + result);
            
            // Wait a bit between requests
            Thread.sleep(1000);
        }
    }
}
```
