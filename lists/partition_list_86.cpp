#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

ListNode* partition(ListNode* head, int x) {
    ListNode* l1 = new ListNode();
    ListNode* l2 = new ListNode();
    ListNode* l1_iter = l1;
    ListNode* l2_iter = l2;

    ListNode* iter = head;
    while (iter) {
        if (iter->val < x) {
            l1_iter->next = iter;
            l1_iter = l1_iter->next;
        } else {
            l2_iter->next = iter;
            l2_iter = l2_iter->next;
        }

        iter = iter->next;
    }

    l2_iter->next = nullptr;
    l1_iter->next = l2->next;

    return l1->next;
}

int main() {
    vector<int> valori = {1, 4, 3, 2, 5, 2};
    
    if (valori.empty()) {
        return 0;
    }

    ListNode* head = new ListNode(valori[0]);
    ListNode* curent = head;

    for (int i = 1; i < valori.size(); i++) {
        curent->next = new ListNode(valori[i]);
        curent = curent->next;
    }

    printList(head);

    ListNode* res = partition(head, 3);

    printList(res);

    return 0;
}
