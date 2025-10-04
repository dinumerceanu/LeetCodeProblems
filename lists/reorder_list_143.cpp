#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

ListNode* mergeLists(ListNode* head1, ListNode* head2) {
    ListNode* p = head1;
    ListNode* q = head2;

    while (p != nullptr && q != nullptr) {
        ListNode* nextP = p->next;
        ListNode* nextQ = q->next;

        p->next = q;

        if (nextP != nullptr)
            q->next = nextP;

        p = nextP;
        q = nextQ;
    }

    return head1;
}

void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = slow->next;
    slow->next = nullptr;
    secondHalf = reverseList(secondHalf);
    mergeLists(head, secondHalf);
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= 7; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }

    reorderList(head);

    current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
