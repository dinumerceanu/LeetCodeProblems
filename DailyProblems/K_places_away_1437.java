public class K_places_away_1437 {
    public static boolean kLengthApart(int[] nums, int k) {
        int last_one = -1;

        for (int i = 0; i < nums.length; i++) {
            if (last_one >= 0 && nums[i] == 1 && i - last_one <= k) {
                return false;
            }

            if (nums[i] == 1) {
                last_one = i;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        int[] nums = {1,0,0,1,0,1};
        int k = 2;

        System.out.println(kLengthApart(nums, k));
    }
}
