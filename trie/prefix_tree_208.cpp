#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    char symbol;
    vector<Node*> children;
    bool isWord;

    Node() {
        isWord = false;
    }

    Node(char _symbol) {
        symbol = _symbol;
        isWord = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node('#');
    }

    void insert(const string& word) {
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';

            if (node->children.empty()) {
                node->children = vector<Node*>(26, nullptr);
            }

            if (node->children[idx] == nullptr) {
                node->children[idx] = new Node();
            }

            node = node->children[idx];
        }

        node->isWord = true;
    }

    bool search(const string& word) {
        Node* node = root;

        for (char c : word) {
            int idx = c - 'a';
        
            if (node->children.empty() || node->children[idx] == nullptr) {
                return false;
            }
        
            node = node->children[idx];
        }
        
        return node->isWord;
    }

    bool startsWith(const string& prefix) {
        Node* node = root;
        
        for (char c : prefix) {
            int idx = c - 'a';
        
            if (node->children.empty() || node->children[idx] == nullptr) {
                return false;
            }
        
            node = node->children[idx];
        }
        
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;

    return 0;
}
