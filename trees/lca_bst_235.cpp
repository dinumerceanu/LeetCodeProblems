#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    unordered_set<TreeNode*> set;
    TreeNode* iter = root;

    while (iter) {
        set.insert(iter);

        if (iter == p) {
            break;
        }
        
        if (p->val < iter->val) {
            iter = iter->left;
        } else if (p->val > iter->val) {
            iter = iter->right;
        } else {
            break;
        }
    }

    iter = root;
    TreeNode* best = nullptr;
    while (iter) {
        if (set.find(iter) != set.end()) {
            best = iter;
        }

        if (q->val < iter->val) {
            iter = iter->left;
        } else if (q->val > iter->val) {
            iter = iter->right;
        } else {
            break;
        }
    }

    return best;
}

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;
    TreeNode* q = root->right;


    cout << lowestCommonAncestor(root, p, q)->val << endl;

    return 0;
}
