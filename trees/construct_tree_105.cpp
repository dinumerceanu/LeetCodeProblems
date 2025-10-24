#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void bfs(TreeNode* root) {
    vector<vector<int>> res;

    if (!root) {
        return;
    }

    deque<TreeNode*> q;

    q.push_back(root);
    int onLevel = 1;
    int onNextLevel = 0;

    while (!q.empty()) {
        TreeNode* node;
        vector<int> aux;
        for (int i = 0; i < onLevel; i++) {
            node = q.front();
            q.pop_front();
            aux.push_back(node->val);
            
            if (node->left) {
                q.push_back(node->left);
                onNextLevel++;
            }

            if (node->right) {
                q.push_back(node->right);
                onNextLevel++;
            }
        }

        res.push_back(aux);
        onLevel = onNextLevel;
        onNextLevel = 0;
    }

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

TreeNode* build(const vector<int>& preorder, int inorderStart, int inorderEnd, int& preorderIndex, unordered_map<int, int>& inorderMap) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    int rootValue = preorder[preorderIndex];
    TreeNode* root = new TreeNode(rootValue);
    
    preorderIndex++;

    int inorderRootIndex = inorderMap.at(rootValue);

    root->left = build(preorder, inorderStart, inorderRootIndex - 1, preorderIndex, inorderMap);

    root->right = build(preorder, inorderRootIndex + 1, inorderEnd, preorderIndex, inorderMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderMap;
    int preorderIndex = 0;

    for (int i = 0; i < inorder.size(); ++i) {
        inorderMap[inorder[i]] = i;
    }

    return build(preorder, 0, inorder.size() - 1, preorderIndex, inorderMap);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->right = new TreeNode(20);
    root->left = new TreeNode(9);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    TreeNode* newTree = buildTree(preorder, inorder);

    bfs(newTree);

    return 0;
}
