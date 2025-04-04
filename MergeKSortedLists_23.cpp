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

void add(ListNode*& list, int x) {
    if (list == nullptr) {
        list = new ListNode(x);
        return;
    }
    ListNode* iter = list;
    while (iter->next != nullptr) {
        iter = iter->next;
    }
    iter->next = new ListNode(x);
}

void printList(ListNode* list) {
    if (list == nullptr) return;
    ListNode* iter = list;
    while (iter != nullptr) {
        cout<<iter->val<<" ";
        iter = iter->next;
    }
    cout<<endl;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
    if (left > right) return nullptr;
    if (left == right) return lists[left];
    
    int mid = (left + right) / 2;
    ListNode* l1 = mergeKLists(lists, left, mid);
    ListNode* l2 = mergeKLists(lists, mid + 1, right);
    return mergeTwoLists(l1, l2);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    return mergeKLists(lists, 0, lists.size() - 1);
}

int main() {
    ListNode* list1 = nullptr, *list2 = nullptr, *list3 = nullptr;
    add(list1, 1);
    add(list1, 4);
    add(list1, 5);
    add(list2, 1);
    add(list2, 3);
    add(list2, 4);
    add(list3, 2);
    add(list3, 6);
    vector<ListNode*> lists = {list1, list2, list3};
    printList(mergeKLists(lists));
    
    return 0;
}
