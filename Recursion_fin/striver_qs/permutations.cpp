class Solution {
public:
    /**
     * @param a - The original numbers.
     * @param ds - The current permutation we are building.
     * @param res - The final list of all permutations.
     * @param visited - Tracks which *indices* are already in 'ds'.
     */
    void helper(vector<int>& a, vector<vector<int>>& res, vector<int>& ds, vector<bool>& visited) {
        
        // Base Case: If our permutation 'ds' is the same size as 'a',
        // we have a complete permutation.
        if (ds.size() == a.size()) {
            res.push_back(ds);
            return;
        }

        // --- Recursive Step ---
        
        // At *every* level, we loop through ALL possible numbers (from index 0)
        for (int i = 0; i < a.size(); i++) {
            
            // The key: Only proceed if this number (at index i)
            // has not been visited (used) yet.
            if (!visited[i]) {
                
                // 1. Choose:
                visited[i] = true;      // Mark as used
                ds.push_back(a[i]);     // Add the number
                
                // 2. Explore:
                // Recurse to fill the *next* slot.
                // Notice we don't pass 'i' or any index here.
                helper(a, res, ds, visited);
                
                // 3. Unchoose (Backtrack):
                // This happens *after* the recursive call returns.
                ds.pop_back();          // Remove the number
                visited[i] = false;     // Unmark it, so it can be used in other permutations
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        
        // Create a 'visited' array, all set to 'false'
        vector<bool> visited(nums.size(), false);
        
        helper(nums, res, ds, visited);
        return res;
    }
};