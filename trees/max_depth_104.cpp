#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printInorder(TreeNode* root) {
    if (!root) {
        return;
    }

    printInorder(root->left);

    cout << root->val << " ";

    printInorder(root->right);
}

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    } else {
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    printInorder(root);
    cout << endl;

    cout << maxDepth(root) << endl;


    return 0;
}
