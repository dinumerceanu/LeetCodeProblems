package Stack;

import java.util.Scanner;
import java.util.Stack;

public class ValidParantheses {
    public static boolean isValid(String s) {
        if (s == null || s.length() == 0 || s.length() == 1) return false;
        Stack<Character> stack = new Stack<>();
        char new_s[] = s.toCharArray();
        stack.push(new_s[0]);
        for (int i = 1; i < new_s.length; i++) {
            if (stack.empty() == false && ((stack.peek() == '(' && new_s[i] == ')')
            || (stack.peek() == '[' && new_s[i] == ']')
            || (stack.peek() == '{' && new_s[i] == '}'))) {
                stack.pop();
            } else {
                stack.push(new_s[i]);
            }
        }
        if (stack.empty()) return true;
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();
        System.out.println(isValid(s));
    }
}
