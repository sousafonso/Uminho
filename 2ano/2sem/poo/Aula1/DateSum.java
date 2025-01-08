public class DateSum {

    public static void main(String[] args) {
        // int[] date1 = {2, 14, 53, 25}; // example date 1: 2d 14h 53m 25s
        // int[] date2 = {3, 10, 6, 40};  // example date 2: 3d 10h 6m 40s

        int[] result = sumDates(date1, date2);
        System.out.printf("%dd %dh %dm %ds%n", result[0], result[1], result[2], result[3]);
    }

    public static int[] sumDates(int[] date1, int[] date2) {
        int totalSeconds = date1[3] + date2[3];
        int totalMinutes = date1[2] + date2[2] + totalSeconds / 60;
        int totalHours = date1[1] + date2[1] + totalMinutes / 60;
        int totalDays = date1[0] + date2[0] + totalHours / 24;

        totalSeconds %= 60;
        totalMinutes %= 60;
        totalHours %= 24;

        return new int[]{totalDays, totalHours, totalMinutes, totalSeconds};
    }
}
