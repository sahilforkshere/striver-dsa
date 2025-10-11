#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> a, int target)
{
    sort(a.begin(), a.end());
    int n = a.size();

    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start +(end-start) / 2;

        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int t;
    cout << "Enter which element you want to search";
    cin >> t;
    vector<int> a = {1, 3, 5, 12, 15, 17, 19};
    int ans = binarySearch(a, t);
    cout << ans;
    return 0;
}