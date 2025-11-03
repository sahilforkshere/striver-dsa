#include <bits/stdc++.h>
using namespace std;

int printSumk(int ind, int s, int sum, vector<int> &a, int n)
{
    if (ind == n)
    {
        //condition satisfied
        if (s == sum)
        {
            // for (auto it : ds)
            // {
            //     cout << it << " ";
            // }
            cout << endl;
            return 1;
        }
        return 0;
    }

  //  ds.push_back(a[ind]);
    s += a[ind];
    int l=printSumk(ind + 1, s, sum, a, n);

    s -= a[ind];
  //  ds.pop_back();
    // not pick
    int r=printSumk(ind + 1, s, sum, a, n);
    


    return l+r;
}

int main()
{
    vector<int> arr = {1, 2, 1};

    vector<int> ds;
    cout<< printSumk(0,  0, 3, arr, 3);
    return 0;
}