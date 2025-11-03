#include <bits/stdc++.h>
using namespace std;

bool printSumk(int ind, vector<int> &ds, int s, int sum, vector<int> &a, int n)
{
    if (ind == n)
    {
        //condition satisfied
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    ds.push_back(a[ind]);
    s += a[ind];
    if(printSumk(ind + 1, ds, s, sum, a, n)==true){
return true;
    }

    s -= a[ind];
    ds.pop_back();
    // not pick
    if(printSumk(ind + 1, ds, s, sum, a, n)==true) return true;

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 1};

    vector<int> ds;
    printSumk(0, ds, 0, 3, arr, 3);
    return 0;
}