/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
       void parents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &par,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                par[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right]=node;
                q.push(node->right);
            }
        }
       }

       


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       unordered_map<TreeNode*,TreeNode*> par;
      parents(root,par,target);
      unordered_map<TreeNode*,bool> vis;
      queue<TreeNode*> q;
      q.push(target);
      vis[target]=true;
      int curr_level=0;
      while(!q.empty()){
        int sz=q.size();
        if(curr_level++ ==k) break;
        for(int i=0;i<sz;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                q.push(node->left);
                vis[node->left]=true;
            }
            if(node->right && ! vis[node->right]){
                q.push(node->right);
                vis[node->right]=true;
            }
            if(par[node] && !vis[par[node]]){
                q.push(par[node]);
                vis[par[node]]=true;
            }
        }
      }
      vector<int> res;
      while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        res.push_back(curr->val);
      }
      return res;

    }
};