#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &a, int n)
{
    int low = 0;
    int high = a.size() - 1;
    int ans = a.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] >= n)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cout << "Enter which element you to find lower find";
    cin >> t;
    vector<int> a = {1, 3, 5, 12, 15, 17, 19};
    int ans = lowerBound(a, t);
    cout << ans;
    return 0;
}