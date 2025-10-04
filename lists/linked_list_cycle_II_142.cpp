#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> set;
    ListNode* iter = head;

    while (iter) {
        if(set.find(iter) == set.end()) {
            set.insert(iter);
        } else {
            return iter;
        }

        iter = iter->next;
    }

    return nullptr;
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    ListNode* res = detectCycle(head);
    if (res) {
        cout << res->val << endl;
    } else {
        cout << "null" << endl;
    }

    return 0;
}
