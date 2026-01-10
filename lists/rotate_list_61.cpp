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

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
        return head;
    }

    int size = 1;
    ListNode* iter = head;
    while (iter->next) {
        size++;
        iter = iter->next;
    }

    int count = k % size;
    if (count == 0) {
        return head;
    }

    iter->next = head;

    ListNode* temp = head;
    for (int i = 0; i < size - count - 1; i++) {
        temp = temp->next;
    }

    ListNode* newHead = temp->next;
    temp->next = nullptr;

    return newHead;
}

int main() {
    vector<int> valori = {0, 1, 2};
    
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

    ListNode* newHead = rotateRight(head, 4);

    printList(newHead);

    return 0;
}
