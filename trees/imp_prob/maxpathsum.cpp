class Solution {
public:
    int total = INT_MIN; // track global maximum

    int maxSum(TreeNode* root) {
        if (!root) return 0;

        // Get max path sum from left and right, ignore negative paths
        int leftSum  = max(0, maxSum(root->left));
        int rightSum = max(0, maxSum(root->right));

        // Update global maximum with path through current node
        total = max(total, leftSum + rightSum + root->val);

        // Return best single-side path to parent
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return total;
    }
};
