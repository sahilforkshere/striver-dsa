class Solution {
  public:

    bool isLeaf(Node* root) {
        if (root == nullptr)
            return false;
        return (root->left == nullptr && root->right == nullptr);
    }

    void addLeft(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr != nullptr && !isLeaf(curr)) {
            res.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addRight(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;
        while (curr != nullptr && !isLeaf(curr)) {
            temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        // Add in reverse
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    void addLeafs(Node* root, vector<int>& res) {
        if (root == nullptr) return;

        if (isLeaf(root)) {
            res.push_back(root->data);
        }
        addLeafs(root->left, res);
        addLeafs(root->right, res);
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        // 1) Root
        if (!isLeaf(root)) {
            ans.push_back(root->data);
        }

        // 2) Left boundary (excluding leaves)
        addLeft(root, ans);

        // 3) All leaves
        addLeafs(root, ans);

        // 4) Right boundary (excluding leaves) in reverse
        addRight(root, ans);

        return ans;
    }
};