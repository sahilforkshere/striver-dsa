#include <bits/stdc++.h>
using namespace std;
void helper(int ind, vector<int> &a, vector<vector<int>> &res, vector<int> &ds)
{
    if (ind == a.size())
    {
        res.push_back(ds);
        return;
    }
    if (ind < a.size())
    {
        ds.push_back(a[ind]);
        helper(ind + 1, a, res, ds);
        ds.pop_back();
    }

    helper(ind + 1, a, res, ds);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> ds;
    vector<vector<int>> res;
    helper(0, nums, res, ds);
    return res;
}
int main()
{
    vector <int> a={1,2,3};
    vector <vector<int>> ans=subsetsWithDup(a);
    for (vector<int> v : ans)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout<<v[i];
        }
        cout<<" ";
    }
    



    return 0;
}