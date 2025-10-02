package LeetCodeProblems.DailyProblems;

public class Water_bottles_II_3100 {
    public static int maxBottlesDrunk(int numBottles, int numExchange) {
        int drinkedBottles = numBottles;
        int emptyBottles = numBottles;
        numBottles = 0;

        while (emptyBottles >= numExchange) {
            emptyBottles -= numExchange;
            emptyBottles += 1;
            drinkedBottles += 1;
            numExchange += 1;
        }

        return drinkedBottles;
    }
    public static void main(String[] args) {
        int numBottles = 10, numExchange = 3;

        System.out.println(maxBottlesDrunk(numBottles, numExchange));
    }
}
