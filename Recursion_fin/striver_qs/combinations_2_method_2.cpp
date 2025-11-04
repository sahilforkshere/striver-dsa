#include <vector>
#include <iostream>
#include <algorithm> // Needed for sort()

using namespace std;

class Solution {
public:
    /**
     * @brief Recursive helper function to find combinations.
     * @param ind The starting index in the 'candidates' array to consider.
     * @param ds The current combination being built (dynamic subset).
     * @param sum The remaining target sum we need to achieve.
     * @param a The sorted 'candidates' array.
     * @param n The size of the 'candidates' array.
     * @param res The final list of unique combinations.
     */
    void helper(int ind, vector<int>& ds, int sum, vector<int>& a, int n,
                vector<vector<int>>& res) {
        
       // Base Case: If the target sum is 0, we found a valid combination.
       if (sum == 0)
       {
        // Add a *copy* of the current combination (ds) to our result (res).
        res.push_back(ds);
        return; // Backtrack from this path.
       }

       // --- This loop is the core logic ---
       // We iterate from the current starting index 'ind' to the end of the array.
       // This loop structure *replaces* the explicit "pick" and "not pick" calls.
       for (int i = ind; i < n; i++)
       {
        // *** This is the CRUCIAL check for Combination Sum II ***
        // We need to avoid duplicate *combinations*.
        // If i > ind: We are *not* at the first element of this recursive call's loop.
        // a[i] == a[i-1]: The current element is the same as the *previous* element.
        //
        // This means we have already considered a combination starting with
        // a[i-1] in a previous loop iteration. To avoid creating a duplicate
        // combination (e.g., [1, 2, 2] using the first '2' and [1, 2, 2] using
        // the second '2'), we *skip* this element.
        if (i > ind && a[i] == a[i-1])
        {
            continue; // Skip this duplicate element.
        }

        // *** Optimization / Pruning ***
        // Since the array is sorted, if the current element (a[i]) is
        // greater than the remaining sum, then all elements after it
        // will also be too large. We can stop searching this path.
        if (a[i] > sum)
        {
            break; // No need to check further.
        }
        
        // --- "Pick" Step ---
        // If we've passed the checks, we "pick" the current element a[i].
        ds.push_back(a[i]);

        // --- Recursive Call ---
        // We call the helper function again.
        // Key: The new starting index is 'i + 1'. This is because
        // in Combination Sum II, we can only use each *element* (by index)
        // at most *once* in any single combination.
        helper(i + 1, ds, sum - a[i], a, n, res);
        
        // --- "Backtrack" Step ---
        // After the recursive call returns (meaning we've explored all
        // combinations *with* a[i]), we remove a[i] from 'ds'.
        // This "un-picks" the element, allowing the 'for' loop to
        // continue to the next element (i+1) to build a new path.
        ds.pop_back();
       }
    }

    // Function to find unique combinations that sum up to a target.
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;          // To store the current combination.
        vector<vector<int>> res; // To store all valid unique combinations.

        // *** CRITICAL FIRST STEP ***
        // Sorting is essential for two reasons:
        // 1. It allows us to easily skip duplicates (the i > ind && a[i] == a[i-1] check).
        // 2. It enables the optimization (a[i] > sum) to work.
        sort(candidates.begin(), candidates.end());
        
        // Start the recursive process from index 0.
        helper(0, ds, target, candidates, candidates.size(), res);
        return res;
    }
};
