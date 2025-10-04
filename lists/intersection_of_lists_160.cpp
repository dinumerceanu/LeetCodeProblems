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
 
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> set;
    ListNode* iterA = headA;
    ListNode* iterB = headB;

    while (iterA) {
        set.insert(iterA);
        iterA = iterA->next;
    }

    while (iterB) {
        if (set.find(iterB) != set.end()) {
            return iterB;
        } else {
            iterB = iterB->next;
        }
    }

    return nullptr;
}

int main() {
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(9);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = intersect;

    ListNode* headB = new ListNode(3);
    headB->next = new ListNode(4);
    headB->next->next = new ListNode(5);
    headB->next->next->next = intersect;

    ListNode* result = getIntersectionNode(headA, headB);

    if (result) {
        cout << result->val << endl;
    } else {
        cout << "null" << endl;
    }

    return 0;
}
