package DiviteEtImperta;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class findMinInRotatedArr {

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

        return nums[left];
    }

    public static void main(String[] args) {
        File in_file = new File("file.in");
        try {
            Scanner scanner = new Scanner(in_file);
            List<Integer> list = new ArrayList<>();
            while (scanner.hasNextInt()) {
                list.add(scanner.nextInt());
            }
            int[] nums = new int[list.size()];
            for (int i = 0; i < list.size(); i++) {
                nums[i] = list.get(i);
            }

            System.out.println(findMin(nums));

        } catch (FileNotFoundException e) {
            System.out.println("Error");
            e.printStackTrace();
        }
        
    }    
}
