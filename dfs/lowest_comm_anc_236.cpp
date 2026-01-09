#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr) {
        return root;
    }

    return (left != nullptr) ? left : right;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << lca->val << endl;
    } else {
        cout << "NULL\n";
    }

    return 0;
}
