package Aula9;

import Aula9.*;

public class MarketingNotifier implements FilterAvailabilityObserver {
    
    @Override
    public void onNewFilterAvailable(String filterName, String description, String category) {
        System.out.println("[MARKETING] Sending promotional email about " + filterName + " (Category: " + category + ").");
        // Example output: "[MARKETING] Sending promotional email about [filterName] (Category: [category])."
    }
}