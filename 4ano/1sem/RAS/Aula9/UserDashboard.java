package Aula9;

import Aula9.*;

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