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

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node('#');
    }
    
    void addWord(string word) {
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
    
    bool search_aux(string word, Node* parent) {
        //search for word in "parent" subtree

        Node* node = parent;

        if (!node) {
            return false;
        }

        if (word.empty()) {
            return node->isWord;
        }

        char c = word[0];

        if (c == '.') {
            for (int i = 0; i < node->children.size(); i++) {
                if (node->children[i] != nullptr && search_aux(word.substr(1), node->children[i])) {
                    return true;
                }
            }
            
            return false;

        } else {
            int idx = c - 'a';
            
            if (node->children.empty() || node->children[idx] == nullptr) {
                return false;
            }

            return search_aux(word.substr(1), node->children[idx]);
        }
    }

    bool search(string word) {
        return search_aux(word, root);
    }
};

int main() {
    WordDictionary wordDict;

    wordDict.addWord("bad");
    wordDict.addWord("dad");
    wordDict.addWord("mad");

    cout << wordDict.search("pad") << endl;
    cout << wordDict.search("bad") << endl;
    cout << wordDict.search(".ad") << endl;
    cout << wordDict.search("b..") << endl;

    return 0;
}
