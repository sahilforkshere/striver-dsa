#ifndef CREATE_TREE_H
#define CREATE_TREE_H

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Declaration
TreeNode* insertNode(TreeNode* root, int val);
void inorderTraversal(TreeNode* root);

// Definition
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

#endif // CREATE_TREE_H
