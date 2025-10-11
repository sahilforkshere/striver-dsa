#include <bits/stdc++.h>
using namespace std;

int longestSubarraywithK(vector<int> &a, long long k)
{
    int left = 0;
    int right = 0;
    int len = 0;
    long long sum = a[0];
    int maxi = 0;

    while (right < a.size())
    {
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }

        if (sum == k)
        {
            maxi = max(maxi, right - left + 1);
        }

        right++;
        if (right < a.size())
        {
            sum += a[right];
        }
    }

    return maxi;
}
int main()
{
    vector<int> a = {1, 2, 3, 1, 1, 1, 4, 2, 3};
    int k;
    cout << "Enter for which sum u have to find subarray\n";
    cin >> k;

    int ans = longestSubarraywithK(a, k);
    cout << ans;
    return 0;
}