import java.time.LocalDate;
import java.util.Scanner;

public class DayOfWeekCalculator {
    public static void main (String [] args){
        int dayOfWeek = calculateDayOfWeek(day, month, year);
        System.out.println("Day of the week: " + dayOfWeek);
    }

    public static int calculateDayOfWeek (int day, int month, int year){
        int totalDays = 0;

        // Step (a): Calculate the total number of days
        int yearsSince1900 = year - 1900;
        totalDays += yearsSince1900 * 365;

        // Add leap year days
        totalDays += yearsSince1900 / 4;

        // Subtract a day if the given year is a leap year and the month is January or February
        if (isLeapYear(year) && (month == 1 || month == 2)) {
            totalDays -= 1;
        }

        // Add days of the current year up to the given date
        totalDays += daysInCurrentYear(day, month, year);

        // Step (b): Calculate integer division by 7
        int weekDay = totalDays % 7;

        return weekDay;
    }

    public static boolean isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                return year % 400 == 0;
            } else {
                return true;
            }
        }
        return false;
    }

    public static int daysInCurrentYear(int day, int month, int year) {
        int[] daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(year)) {
            daysInMonths[1] = 29; // February has 29 days in a leap year
        }

        int days = 0;
        for (int i = 0; i < month - 1; i++) {
            days += daysInMonths[i];
        }
        days += day;

        return days;
    }
}