package LeetCodeProblems.DailyProblems;

import java.lang.Math;

public class Containter_with_most_water_11 {

    public static int maxArea(int[] height) {
        int left = 0, right = height.length - 1, maxArea = 0;

        while (left < right) {
            int area = (right - left) * Math.min(height[right], height[left]);

            if (maxArea < area) {
                maxArea = area;
            }

            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return maxArea;
    }

    public static void main(String[] args) {
        int[] height = {1,8,6,2,5,4,8,3,7};

        System.out.println(maxArea(height));
    }
}
