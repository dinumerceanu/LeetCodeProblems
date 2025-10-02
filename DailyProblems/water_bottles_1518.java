package LeetCodeProblems.DailyProblems;

public class water_bottles_1518 {
    public static int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles, emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int newFilled = emptyBottles / numExchange;
            sum += newFilled;
            emptyBottles = emptyBottles % numExchange + newFilled;
        }

        return sum;
    }

    public static void main(String[] args) {
        System.out.println(numWaterBottles(9, 3));
    }
}
