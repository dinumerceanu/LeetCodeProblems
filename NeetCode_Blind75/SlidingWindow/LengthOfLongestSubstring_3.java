package SlidingWindow;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class LengthOfLongestSubstring_3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        scanner.close();
        System.out.println(str);
        System.out.println(lengthOfLongestSubstring(str));
    }

    public static int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        char char_arr[] = s.toCharArray();
        int left = 0, right = 0, max_length = 0;
        while (right < char_arr.length) {
            if (!set.contains(char_arr[right])) {
                set.add(char_arr[right]);
                right++;
                if (right - left > max_length) {
                    max_length = right - left;
                }
            } else {
                set.remove(char_arr[left]);
                left++;
            }
        }

        return max_length;
    }
}
