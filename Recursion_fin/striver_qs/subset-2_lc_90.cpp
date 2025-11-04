#include <vector>
#include <iostream>
#include <algorithm> // Needed for sort()

using namespace std;

class Solution {
public:
    /**
     * Helper function using the pick/not-pick pattern.
     * @param ind The current index we are considering.
     * @param a   The sorted input array.
     * @param res The final list of subsets (passed by reference &).
     * @param ds  The current subset being built (passed by reference &).
     */
    void helper(int ind, vector<int>& a, vector<vector<int>>& res, vector<int>& ds) {
        
        // --- Base Case ---
        // If we've considered all elements, add the current subset
        // to our result and stop this recursive path.
        if (ind == a.size()) {
            res.push_back(ds);
            return;
        }

        // --- 1. "Pick" Choice ---
        // Add the current number a[ind] to our subset.
        ds.push_back(a[ind]);
        // Recurse, moving to the next index.
        helper(ind + 1, a, res, ds);
        // Backtrack: Remove the number we just added.
        ds.pop_back();

        
        // --- 2. "Not Pick" Choice (with Duplicate Skip) ---
        
        // Find the index of the *next* number that is *different*
        // from the current one (a[ind]).
        int next_ind = ind + 1;
        while (next_ind < a.size() && a[next_ind] == a[ind]) {
            next_ind++;
        }
        
        // Recurse, but *start* from that next different index.
        // This skips all duplicates of a[ind].
        helper(next_ind, a, res, ds);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> res;

        // **CHANGE 1: Sort the array**
        // This is required to group duplicates together.
        sort(nums.begin(), nums.end());

        // Start the recursion from the first element (index 0)
        helper(0, nums, res, ds);
        
        return res;
    }
};