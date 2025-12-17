#include  <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Helper Function: Calculates Largest Rectangle in a Histogram (Same as previous code)
    int largestRectangleArea(vector<int>& heights) {
       stack<int> st;
       int n = heights.size();
       int maxi = 0;

       for(int i = 0; i < heights.size(); i++){
        while(!st.empty() && heights[st.top()] > heights[i]){
            int el = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxi = max(heights[el] * (nse - pse - 1), maxi);
        }
        st.push(i);
       }
       while(!st.empty()){
        int nse = n;
        int el = st.top();
        st.pop();
        int pse = st.empty() ? -1 : st.top();
         maxi = max(heights[el] * (nse - pse - 1), maxi);
       }

       return maxi;
    }

    // Main Function: Maximal Rectangle
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Handle edge case for empty matrix
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        
        // Create a 2D array to store the "height" of 1s at each cell
        vector<vector<int>> psum(n, vector<int>(m, 0));
        int maxi = 0;

        // STEP 1: Build the Histogram Heights (Vertical Prefix Sum)
        // We iterate column by column to count consecutive 1s vertically
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                // Convert char to int value
                int val = matrix[i][j] - '0';
                
                sum += val;

                // CRITICAL LOGIC: Reset height on '0'
                // If the current cell is '0', the consecutive chain of 1s breaks.
                // The height of the bar at this point becomes 0.
                if(val == 0){
                    sum = 0;
                }
                
                psum[i][j] = sum;
            }
        }

        // STEP 2: Process Each Row as a Histogram
        // Now, each row in 'psum' represents a histogram of heights built from the rows above it.
        for(int i = 0; i < n; i++){
            // Pass the current row (now a histogram) to your previous function
            // psum[i] is a vector<int> representing heights
            maxi = max(maxi, largestRectangleArea(psum[i]));
        }
        
        return maxi;
    }
};