#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       stack<int> st; // Stack to store indices. We maintain a "monotonic increasing" stack.
       int n = heights.size();
       int maxi = 0; // Variable to store the maximum area found so far.

       // Loop through every bar in the histogram
       for(int i = 0; i < heights.size(); i++){

            // While the stack is not empty AND the current bar is smaller than the bar at the stack's top:
            // This means we have found the "Next Smaller Element" (NSE) for the bar at st.top().
            // The current index 'i' acts as the right boundary (exclusive) for the popped element.
            while(!st.empty() && heights[st.top()] > heights[i]){
                int el = st.top(); // The index of the bar whose height determines the rectangle height
                st.pop();

                int nse = i; // NSE index: The right boundary (current index)

                // PSE index: The Previous Smaller Element is the new top of the stack after popping.
                // If the stack is empty, it means there is no smaller element to the left, so boundary is -1.
                int pse = st.empty() ? -1 : st.top();

                // Calculate area: height * width
                // width = right_boundary - left_boundary - 1
                maxi = max(heights[el] * (nse - pse - 1), maxi);
            }

            // Push the current index onto the stack
            st.push(i);
       }

       // After the loop, the stack might not be empty.
       // These remaining bars never found a "Next Smaller Element" to their right.
       // Therefore, their right boundary extends to the end of the array (index n).
       while(!st.empty()){
            int nse = n; // Right boundary is the size of the array
            int el = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top(); // Left boundary logic remains the same

            // Calculate area for remaining elements
            maxi = max(heights[el] * (nse - pse - 1), maxi);
       }

       return maxi;
    }
};
int main()
{
    return 0;
}
