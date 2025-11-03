#include <bits/stdc++.h>
using namespace std;

void printSumk(int ind, vector<int> &ds, int s, int sum, vector<int> &a, int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    ds.push_back(a[ind]);
    s += a[ind];
    printSumk(ind + 1, ds, s, sum, a, n);

    s -= a[ind];
    ds.pop_back();
    // not pick
    printSumk(ind + 1, ds, s, sum, a, n);
}

int main()
{
    vector<int> arr = {1, 2, 1};

    vector<int> ds;
    printSumk(0, ds, 0, 3, arr, 3);
    return 0;
}