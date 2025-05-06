#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode* root, int max_value_so_far, int &good_nodes) {
    if (root->left) {
        if (root->left->val >= max_value_so_far) {
            good_nodes++;
            dfs(root->left, root->left->val, good_nodes);
            
        } else {
            dfs(root->left, max_value_so_far, good_nodes);
        }
    }
    if (root->right) {
        if (root->right->val >= max_value_so_far) {
            good_nodes++;
            dfs(root->right, root->right->val, good_nodes);
            
        } else {
            dfs(root->right, max_value_so_far, good_nodes);
        }
    }
}

int goodNodes(TreeNode* root) {
    int good_nodes = 1;
    if (root)
        dfs(root, root->val, good_nodes);
    return good_nodes;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    cout<<goodNodes(root);

    return 0;
}