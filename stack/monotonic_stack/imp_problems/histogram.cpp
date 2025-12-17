#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmaller(vector<int>& v) {
        vector<int> result;
        stack<int> s;
        for (int i = v.size() - 1; i >= 0; i--) {
            while (!s.empty() && v[s.top()] >= v[i]) {
                s.pop();
            }

            if (s.empty()) {
                result.push_back(v.size());
            } else {
                result.push_back(s.top());
            }
            s.push(i);
        }

        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> previousSmaller(vector<int>& v) {
        vector<int> result;
        stack<int> s;
        for (int i = 0; i < v.size(); i++) {
            while (!s.empty() && v[s.top()] > v[i]) {
                s.pop();
            }
            if (s.empty()) {
                result.push_back(-1);
            } else {
                result.push_back(s.top());
            }
            s.push(i);
        }
        return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ar = 0;

        vector<int> pse = previousSmaller(heights);
        vector<int> nse = nextSmaller(heights);

        for (int i = 0; i < n; i++) {
            int lft = pse[i] + 1;
            int rht = nse[i] - 1;

            int width = rht - lft + 1;
            int area = width * heights[i];

            ar = max(ar, area);
        }
        return ar;
    }
};

int main() {
    int n;
    cin >> n;              // number of bars

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i]; // heights input
    }

    Solution sol;
    cout << sol.largestRectangleArea(heights) << endl;

    return 0;
}
