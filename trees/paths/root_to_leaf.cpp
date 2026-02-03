/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
        void solve(Node* root,vector<int> &curr,vector<vector<int>>& ans){
            if(root==nullptr){
                return ;
            }
            curr.push_back(root->data);
            if(root->left==nullptr && root->right==nullptr){
                ans.push_back(curr);
            }else{
                solve(root->left,curr,ans);
                solve(root->right,curr,ans);
            }
            
            curr.pop_back();
        }
    vector<vector<int>> Paths(Node* root) {
       
        vector<vector<int>> ans;
        vector<int> curr;
        if (root == nullptr) return ans;
        solve(root, curr, ans);
        return ans;
        
    }
};