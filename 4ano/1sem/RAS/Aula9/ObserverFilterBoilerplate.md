# Boilerplate Code for Observer Pattern Exercise (New Filters)

This document contains the starting code for the Observer Pattern exercise. You should create the following files in your Java project.

## 1. FilterAvailabilityObserver.java
Interface for any entity that wants to be notified about new filters.

```java
package com.picturas.observer;

public interface FilterAvailabilityObserver {
    /**
     * Called when a new filter is registered in the system.
     * @param filterName The name of the new filter.
     * @param description A brief description of what the filter does.
     * @param category The category of the filter (e.g., "Color", "AI", "Distortion").
     */
    void onNewFilterAvailable(String filterName, String description, String category);
}
```

## 2. FilterRegistry.java
The Subject (Observable) class that manages filters and observers.

```java
package com.picturas.registry;

import com.picturas.observer.FilterAvailabilityObserver;
import java.util.ArrayList;
import java.util.List;

public class FilterRegistry {
    private List<FilterAvailabilityObserver> observers = new ArrayList<>();
    private List<String> availableFilters = new ArrayList<>();

    /**
     * Registers a new observer to receive notifications.
     * @param observer The observer to add.
     */
    public void subscribe(FilterAvailabilityObserver observer) {
        observers.add(observer);
    }

    /**
     * Removes an observer from the notification list.
     * @param observer The observer to remove.
     */
    public void unsubscribe(FilterAvailabilityObserver observer) {
        observers.remove(observer);
    }

    /**
     * Registers a new filter and notifies all observers.
     * @param name Name of the filter.
     * @param description Description of the filter.
     * @param category Category of the filter.
     */
    public void registerNewFilter(String name, String description, String category) {
        System.out.println(">>> Registering new filter: " + name);
        availableFilters.add(name);
        
        notifyObservers(name, description, category);
    }

    /**
     * Helper method to notify all registered observers.
     */
    private void notifyObservers(String name, String description, String category) {
        for (FilterAvailabilityObserver observer : observers) {
            observer.onNewFilterAvailable(name, description, category);
        }
    }
}
```

## 3. UserDashboard.java
A concrete observer representing the user interface.

```java
package com.picturas.ui;

import com.picturas.observer.FilterAvailabilityObserver;

public class UserDashboard implements FilterAvailabilityObserver {
    private String username;

    public UserDashboard(String username) {
        this.username = username;
    }

    @Override
    public void onNewFilterAvailable(String filterName, String description, String category) {
        System.out.println("Displaying toast notification to user " + username + ": New filter " + filterName + " is now available!");
        // Example output: "Displaying toast notification to user [username]: New filter [filterName] is now available!"
    }
}
```

## 4. MarketingNotifier.java
A concrete observer representing the marketing system.

```java
package com.picturas.marketing;

import com.picturas.observer.FilterAvailabilityObserver;

public class MarketingNotifier implements FilterAvailabilityObserver {
    
    @Override
    public void onNewFilterAvailable(String filterName, String description, String category) {
        System.out.println("[MARKETING] Sending promotional email about " + filterName + " (Category: " + category + ").");
        // Example output: "[MARKETING] Sending promotional email about [filterName] (Category: [category])."
    }
}
```

## 5. Main.java
A test class to simulate the scenario.

```java
package com.picturas;

import com.picturas.registry.FilterRegistry;
import com.picturas.ui.UserDashboard;
import com.picturas.marketing.MarketingNotifier;

public class Main {
    public static void main(String[] args) {
        // 1. Create the Subject (FilterRegistry)
        FilterRegistry registry = new FilterRegistry();

        // 2. Create Observers
        UserDashboard user1 = new UserDashboard("Alice");
        UserDashboard user2 = new UserDashboard("Bob");
        MarketingNotifier marketing = new MarketingNotifier();

        // 3. Subscribe Observers
        System.out.println("--- Subscribing Observers ---");
        registry.subscribe(user1);
        registry.subscribe(user2);
        registry.subscribe(marketing);

        // 4. Register a new filter (should trigger notifications)
        System.out.println("\n--- Adding 'Sepia Pro' Filter ---");
        registry.registerNewFilter("Sepia Pro", "Classic vintage look", "Color");

        // 5. Unsubscribe one user
        System.out.println("\n--- Bob unsubscribes ---");
        registry.unsubscribe(user2);

        // 6. Register another filter (Bob should NOT be notified)
        System.out.println("\n--- Adding 'AI Face Smooth' Filter ---");
        registry.registerNewFilter("AI Face Smooth", "Removes blemishes using AI", "AI");
    }
}
```
