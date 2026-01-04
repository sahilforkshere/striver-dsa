
#include <bits/stdc++.h>
#include  "../create_tree.h"
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> preorder;
        if (root=NULL) return preorder;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty())
        {
            root=s.top();
            s.pop();
            preorder.push_back(root->val);

            if (root->right!=NULL) s.push(root->right);
            if (root->left!=NULL) s.push(root->left);


        }
        return preorder;
    }
    vector<int>inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()==true) break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};

int main()
{
    TreeNode* root=nullptr;
    root=insertNode(root,5);
    root=insertNode(root,6);
    root=insertNode(root,7);



    return 0;
}

