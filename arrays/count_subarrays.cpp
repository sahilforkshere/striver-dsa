#include <bits/stdc++.h>
using namespace std;
int noOfSubarrays(vector<int> a, int k)
{
    int sum=0;
    int prefixSum = 0;
    unordered_map<int, int> map;
    int count=0;
    map[0] = 1;
    for (int i = 0; i < a.size(); i++)
    {
       sum += a[i];
        int rem = sum-k;
        count=count+map[rem];
        map[sum]++;
    }
    return count;

}
int main()
{
    int k;
    cout << "Enter the sum \n";
    cin >> k;

    vector<int> a = {3, 1, 0, 4, 4, 2, -2, 9, -5};
    int ans = noOfSubarrays(a, k);
    cout << ans;

    return 0;
}