#include<bits/stdc++.h>
#include "../create_tree.h "
using namespace std;
//solution in o(N2)

bool check(TreeNode* root){
    if(root==NULL){
        return true;
    }

    int lh= height(root->left);
    int rh= height(root->right);
    if(abs(lh-rh)>1){
        return false;
    }

    bool left= check(root->left);
    bool right=check(root->right);
    if(!left|| !right){
        return false;
    }
    return true;
}

// solution is o(n)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int lh=maxDepth(root->left);
       int rh= maxDepth(root->right);
       if(lh==-1 || rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1 + max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        // if (root==NULL) return true;
        if(maxDepth(root)==-1){
            return false;
        }

        return true;

    }
};
int main()
{
 return 0;
}