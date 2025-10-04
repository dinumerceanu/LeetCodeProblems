#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* aux = new ListNode(0, head);
    ListNode* u = aux;
    ListNode* v = aux;

    for (int i = 0; i < n; i++) {
        v = v->next;
    }

    while (v->next != nullptr) {
        u = u->next;
        v = v->next;
    }

    u->next = u->next->next;

    return aux->next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= 7; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }

    int n = 3;

    head = removeNthFromEnd(head, n);

    current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
