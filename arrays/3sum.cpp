#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ThreeSum(vector<int>& a) {
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 0; i < n - 2; ++i) {
        if (i > 0 && a[i] == a[i - 1]) continue;       
        if (a[i] > 0) break;                           

        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = a[i] + a[j] + a[k];
            if (sum < 0) {
                ++j;
            } else if (sum > 0) {
                --k;
            } else {
                ans.push_back({a[i], a[j], a[k]});
                // skip duplicate j's and k's
                while (j < k && a[j] == a[j + 1]) ++j;
                while (j < k && a[k] == a[k - 1]) --k;
                ++j; --k;
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> a = {-1, 0, 1, -2, 1, 0, 0, 1, -1, 3, 1, -2, 4, -5, 5};
    vector<vector<int>> ans = ThreeSum(a);
    for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
    }
    cout << endl;
}


    return 0;
}