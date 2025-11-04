#include <vector>
#include <iostream>
#include <algorithm> // To sort the final result

using namespace std;

class Solution {
public:
    /**
     * Helper function using the pick/not-pick pattern.
     * @param ind         The current index we are considering.
     * @param a           The input array.
     * @param n           The total size of the array.
     * @param current_sum The sum of the subset we've built *so far* on this path.
     * @param res         The final list of all subset sums (passed by reference &).
     */
    void helper(int ind, vector<int>& a, int n, int current_sum, vector<int>& res) {
        
        // --- Base Case ---
        // If our index 'ind' has reached the end of the array,
        // it means we've made a decision (pick or not-pick) for every element.
        // The 'current_sum' for this path is a valid subset sum.
        if (ind == n) {
            // Add the final sum of this path to our result list.
            res.push_back(current_sum);
            return; // Stop this recursive path
        }

        // --- 1. "Pick" Choice ---
        // We decide to *include* the current element (a[ind]) in our sum.
        
        // Recurse, moving to the next index (ind + 1).
        // Pass the *updated* sum (current_sum + a[ind]).
        helper(ind + 1, a, n, current_sum + a[ind], res);
        

        // --- 2. "Not Pick" Choice ---
        // We decide to *exclude* the current element (a[ind]) from our sum.
        
        // Recurse, moving to the next index (ind + 1).
        // Pass the *same* sum (current_sum), since we didn't add anything.
        helper(ind + 1, a, n, current_sum, res);
        
        // Note: No "backtracking" (like ds.pop_back()) is needed because
        // we are just passing numbers, not modifying a shared list.
    }

    /**
     * This function finds all possible subset sums.
     * (Assuming this is "Subset Sum I" problem)
     */
    vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();
        vector<int> res; // This will store all the final sums
        
        // Start the recursion:
        // - Start at index 0
        // - Pass the array 'arr' and its size 'n'
        // - The sum of an empty set is 0
        // - Pass the result vector 'res' by reference
        helper(0, arr, n, 0, res);
        
        // The problem often asks for the sums to be sorted
        sort(res.begin(), res.end());
        
        return res;
    }
};