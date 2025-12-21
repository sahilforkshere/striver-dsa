#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* insertNode(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;


    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    inorderTraversal(root);
    cout << "\n";

    return 0;
}
