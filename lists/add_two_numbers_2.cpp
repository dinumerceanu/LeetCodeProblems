#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1) {
        return l2;
    }

    if (!l2) {
        return l1;
    }

    ListNode* iter1 = l1;
    ListNode* iter2 = l2;
    ListNode* added = nullptr;
    ListNode* iter_add = added;
    int carry = 0;

    while (iter1 && iter2) {
        int sum = iter1->val + iter2->val + carry;
        if (sum < 10) {
            if (added == nullptr) {
                added = new ListNode(sum, nullptr);
                iter_add = added;
            } else {
                iter_add->next = new ListNode(sum, nullptr);
                iter_add = iter_add->next;
            }

            carry = 0;
        } else {
            if (added == nullptr) {
                added = new ListNode(sum % 10, nullptr);
                iter_add = added;
            } else {
                iter_add->next = new ListNode(sum % 10, nullptr);
                iter_add = iter_add->next;
            }

            carry = 1;
        }

        iter1 = iter1->next;
        iter2 = iter2->next;
    }

    while (iter1) {
        int sum = iter1->val + carry;

        if (sum < 10) {
            iter_add->next = new ListNode(sum, nullptr);
            carry = 0;
        } else {
            iter_add->next = new ListNode(sum % 10, nullptr);
            carry = 1;
        }

        iter1 = iter1->next;
        iter_add = iter_add->next;
    }

    while (iter2) {
        int sum = iter2->val + carry;

        if (sum < 10) {
            iter_add->next = new ListNode(sum, nullptr);
            carry = 0;
        } else {
            iter_add->next = new ListNode(sum % 10, nullptr);
            carry = 1;
        }

        iter2 = iter2->next;
        iter_add = iter_add->next;
    }

    if (carry == 1) {
        iter_add->next = new ListNode(1);
    }

    return added;
}

int main() {
    // ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3, new ListNode(1))));
    // ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(6)));

    ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    ListNode* l1_plus_l2 = addTwoNumbers(l1, l2);

    ListNode* iter = l1_plus_l2;
    while (iter) {
        cout << iter->val << " ";
        iter = iter->next;
    }
    cout << endl;

    return 0;
}
