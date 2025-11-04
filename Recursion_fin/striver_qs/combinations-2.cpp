#include <vector>
#include <iostream>
#include <algorithm> // Needed for sort()

using namespace std;

class Solution {
public:
    void helper(int ind, vector<int>& ds, int sum, vector<int>& a, int n,
                vector<vector<int>>& res) {
        
        // Base case is the same as before
        if (ind == n) {
            if (sum == 0) {
                res.push_back(ds);
            }
            return;
        }
        
        // --- "Pick" Logic ---
        if (a[ind] <= sum) {
            ds.push_back(a[ind]);
            
            // *** CHANGE 2 ***
            // Move to "ind + 1" because we can only use this number once.
            helper(ind + 1, ds, sum - a[ind], a, n, res);
            
            // Backtrack
            ds.pop_back();
        }

        // --- "Not Pick" Logic ---
        
        // *** CHANGE 3 ***
        // Find the index of the *next different* number to avoid duplicates.
        int next_ind = ind + 1;
        while (next_ind < n && a[next_ind] == a[ind]) {
            next_ind++;
        }
        // Recurse from that new index.
        helper(next_ind, ds, sum, a, n, res);
    }

    // Note: The function name is changed for clarity (Sum vs Sum2)
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> res;

        // *** CHANGE 1 ***
        // Sort the array to group duplicates together.
        sort(candidates.begin(), candidates.end());
        
        helper(0, ds, target, candidates, candidates.size(), res);
        return res;
    }
};