package Aula9;

import Aula9.*;

public interface FilterAvailabilityObserver {
    /**
     * Called when a new filter is registered in the system.
     * @param filterName The name of the new filter.
     * @param description A brief description of what the filter does.
     * @param category The category of the filter (e.g., "Color", "AI", "Distortion").
     */
    void onNewFilterAvailable(String filterName, String description, String category);
}
