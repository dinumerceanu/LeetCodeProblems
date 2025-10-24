#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// pair<Node*, unordered_map<Node*, int>> copyRandomList_test(Node* head) {
//     unordered_map<Node*, int> node_iter;
//     node_iter[nullptr] = -1;
//     unordered_map<Node*, int> node_iter2;
//     unordered_map<int, Node*> iter_node;
//     int current_index = 0;
//     Node* iter = head;
//     Node* newHead;
//     Node* newIter;

//     while (iter) {
//         if (iter == head) {
//             newHead = new Node(iter->val);
//             newIter = newHead;
//         } else {
//             newIter->next = new Node(iter->val);
//             newIter = newIter->next;
//         }

//         node_iter[iter] = current_index;
//         node_iter2[newIter] = current_index;
//         iter_node[current_index] = newIter;
//         current_index++;
//         iter = iter->next;
//     }

//     newIter = newHead;
//     iter = head;
//     while (iter) {
//         newIter->random = iter_node[node_iter[iter->random]];
//         newIter = newIter->next;
//         iter = iter->next;
//     }

//     return {newHead, node_iter2};
// }

Node* copyRandomList(Node* head) {
    if (!head) {
        return nullptr;
    }

    unordered_map<Node*, int> node_iter;
    node_iter[nullptr] = -1;
    unordered_map<Node*, int> node_iter2;
    unordered_map<int, Node*> iter_node;
    int current_index = 0;
    Node* iter = head;
    Node* newHead;
    Node* newIter;

    while (iter) {
        if (iter == head) {
            newHead = new Node(iter->val);
            newIter = newHead;
        } else {
            newIter->next = new Node(iter->val);
            newIter = newIter->next;
        }

        node_iter[iter] = current_index;
        node_iter2[newIter] = current_index;
        iter_node[current_index] = newIter;
        current_index++;
        iter = iter->next;
    }

    newIter = newHead;
    iter = head;
    while (iter) {
        newIter->random = iter_node[node_iter[iter->random]];
        newIter = newIter->next;
        iter = iter->next;
    }

    return newHead;
}


void printList(Node* head, unordered_map<Node*, int>& map) {
    Node* iter = head;

    while (iter) {
        Node* rnd = iter->random;

        cout << iter->val << " ";
        if (rnd) {
            cout << map[rnd] << " ";
        } else {
            cout << "NULL";
        }
        cout << endl;

        iter = iter->next;
    }
}

int main() {
    unordered_map<Node*, int> map;

    Node* head = new Node(7);
    map.insert({head, 0});
    head->next = new Node(13);
    map.insert({head->next, 1});
    head->next->next = new Node(11);
    map.insert({head->next->next, 2});
    head->next->next->next = new Node(10);
    map.insert({head->next->next->next, 3});
    head->next->next->next->next = new Node(1);
    map.insert({head->next->next->next->next, 4});    

    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;

    // printList(head, map);

    // pair<Node*, unordered_map<Node*, int>> result = copyRandomList_test(head);

    // printList(result.first, result.second);

    return 0;
}
