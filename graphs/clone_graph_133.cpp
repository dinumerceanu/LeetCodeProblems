#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneRecursively(Node* old_node, unordered_map<Node*, Node*>& newly_formed) {
    if (!old_node) {
        return nullptr;
    }

    if (newly_formed.find(old_node) != newly_formed.end()) {
        return newly_formed[old_node];
    }

    Node* new_node = new Node(old_node->val);

    newly_formed[old_node] = new_node;

    for (auto& neighbor : old_node->neighbors) {
        Node* x = cloneRecursively(neighbor, newly_formed);

        if (x) {
            new_node->neighbors.push_back(x);
        }
    }

    return new_node;
}

Node* cloneGraph(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    unordered_map<Node*, Node*> newly_formed;

    return cloneRecursively(node, newly_formed);
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Node* clonedGraph = cloneGraph(node1);

    for (auto neighbor : clonedGraph->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    return 0;
}
