package LinkedList;

import java.util.Stack;

public class ReorderList {
    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        printList(head);
        reorderList(head);
    }

    public static void reorderList(ListNode head) {
        if (head == null) return;
        ListNode iter = head;
        int length = 0, n;
        Stack<Integer> stack = new Stack<>();

        while (iter != null) {
            stack.push(iter.val);
            iter = iter.next;
            length++;
        }

        // System.out.println(length);

        if (length % 2 == 1) {
            n = length / 2 + 1;
            // System.out.println(n);
        } else {
            n = length / 2;
        }

        iter = head;
        for (int i = 0; i < n; i++) {
            System.out.print(iter.val + " ");
            iter = iter.next;
            if (i != n - 1 || length % 2 == 0) {
                System.out.print(stack.pop() + " ");
            }
        }
    }

    public static void printList(ListNode head) {
        ListNode iter = head;
        while (iter != null) {
            System.out.print(iter.val + " ");
            iter = iter.next;
        }
        System.out.println();
    }
}

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
