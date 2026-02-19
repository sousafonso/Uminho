package Aula9;

import Aula9.*;

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