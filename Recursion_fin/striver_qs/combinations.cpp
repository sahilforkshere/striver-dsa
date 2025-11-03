#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * This is the main recursive function that does all the work.
     *
     * @param ind   This is the index of the candidate number we are currently looking at.
     * @param ds    "ds" stands for "data structure". This is our temporary list 
     * (like a notepad) where we build a single combination (e.g., [2, 2, 3]).
     * @param sum   This is the *remaining* target sum we still need to reach.
     * (e.g., if target is 7 and we picked [2, 2], the remaining sum is 3).
     * @param a     This is just the original 'candidates' array. 'a' is just a shorter name.
     * @param n     This is the total number of elements in the 'candidates' array.
     * We use it to know when we've run out of numbers.
     * @param res   "res" stands for "result". This is our final answer list, where
     * we store all the valid combinations we find.
     */
    void helper(int ind, vector<int>& ds, int sum, vector<int>& a, int n,
                vector<vector<int>>& res) {
        
        // === BASE CASE ===
        // This is our "stopping condition" for the recursion.
        // If our index 'ind' has reached the end of the array (equals 'n'),
        // it means we've considered every possible number.
        if (ind == n) {
            // Now we check: Did we *exactly* hit our target?
            // (i.e., is the remaining sum we need 0?)
            if (sum == 0) {
                // YES! This combination is valid.
                // Add the current combination ('ds') to our final answer list ('res').
                res.push_back(ds);
            }
            // Whether we found a valid sum or not, this path is finished.
            // "return" tells the function to go back up to the previous step.
            return;
        }

        // === RECURSIVE STEPS ===
        // We have two choices for every number: "Pick it" or "Don't pick it".

        // --- CHOICE 1: "PICK" the number ---
        
        // First, check if we *can* pick this number.
        // Is the current number (a[ind]) less than or equal to the sum we still need?
        if (a[ind] <= sum) {
            // Yes, we can. Let's *try* picking it.
            // 1. Add the current number to our temporary list.
            ds.push_back(a[ind]);

            // 2. Call the helper function again (recursion).
            //    - ind: We stay at the *same index* because we can use this number
            //           multiple times (e.g., pick '2' again).
            //    - ds:  Pass along the *updated* list (which now has a[ind] in it).
            //    - sum: Pass the *new* remaining sum (our old sum *minus* the number
            //           we just picked).
            helper(ind, ds, sum - a[ind], a, n, res);

            // 3. BACKTRACK (The most important step!)
            //    After the function call above *completely finishes* (all its 
            //    own "pick" and "not pick" paths are done), we come back here.
            //    We *remove* the number we just added.
            //    This is like "un-doing" our choice, so we can now explore
            //    the *other* choice ("Don't Pick").
            ds.pop_back();
        }

        // --- CHOICE 2: "DON'T PICK" the number ---
        
        // We explore the path where we *skip* the current number (a[ind]).
        //
        // Call the helper function again:
        //    - ind + 1: Move on to the *next* number in the list.
        //    - ds:      Pass the list *as it is* (we didn't add anything).
        //    - sum:     Pass the sum *as it is* (it didn't change because
        //               we didn't pick a number).
        helper(ind + 1, ds, sum, a, n, res);
    }

    /**
     * This is the starting function that the user calls.
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // This will store our final list of all combinations.
        vector<vector<int>> res; 
        
        // This is the temporary list for building one combination at a time.
        vector<int> ds; 
        
        // Start the recursive "helper" function.
        // We begin at index 0, with the full target sum, the candidate list,
        // its size, and our empty result list.
        helper(0, ds, target, candidates, candidates.size(), res);
        
        // Once all recursive paths are finished, 'res' will be full.
        // Return the final answer.
        return res;
    }
};