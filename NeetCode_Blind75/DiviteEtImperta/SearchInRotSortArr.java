package DiviteEtImperta;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SearchInRotSortArr {

    public static int binarySearch(int[] nums, int target, int start, int stop) {
        while (start <= stop) {
            int mid = start + (stop - start) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                stop = mid - 1;
            }
        }
        return -1;
    }

    public static int search(int[] nums, int target) {
        int min_idx = findMin(nums);
        if (target >= nums[min_idx] && target <= nums[nums.length - 1]) {
            return binarySearch(nums, target, min_idx, nums.length - 1);
        } else {
            return binarySearch(nums, target, 0, min_idx - 1);
        }
    }

    public static int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    public static void main(String[] args) {
        File in_file = new File("file.in");
        try {
            Scanner scanner = new Scanner(in_file);
            List<Integer> list = new ArrayList<>();
            while (scanner.hasNextInt()) {
                list.add(scanner.nextInt());
            }
            int[] nums = new int[list.size() - 1];
            for (int i = 0; i < list.size() - 1; i++) {
                nums[i] = list.get(i);
            }
            int target = list.get(list.size() - 1);
            // for (int num : nums) {
            //     System.out.print(num + " ");
            // }
            // System.out.println("target:" + target);

            System.out.println(search(nums, target));
            // System.out.println(findMin(nums));

        } catch (FileNotFoundException e) {
            System.out.println("Error");
            e.printStackTrace();
        }
    }    
}
