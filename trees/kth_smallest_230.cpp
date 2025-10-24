#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k) {
    priority_queue<int> minHeap;
    deque<TreeNode*> q;

    q.push_back(root);
    int onLevel = 1;
    int onNextLevel = 0;

    while (!q.empty()) {
        TreeNode* node;
        for (int i = 0; i < onLevel; i++) {
            node = q.front();
            q.pop_front();
            minHeap.push(-node->val);
            
            if (node->left) {
                q.push_back(node->left);
                onNextLevel++;
            }

            if (node->right) {
                q.push_back(node->right);
                onNextLevel++;
            }
        }

        onLevel = onNextLevel;
        onNextLevel = 0;
    }

    for (int i = 0; i < k - 1; i++) {
        minHeap.pop();
    }

    return -minHeap.top();
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);

    int k = 2;

    cout << kthSmallest(root, k) << endl;

    return 0;
}
