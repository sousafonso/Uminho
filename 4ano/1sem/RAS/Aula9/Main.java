package Aula9;

import Aula9.*;

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