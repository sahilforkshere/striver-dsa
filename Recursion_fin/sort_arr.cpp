#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &a, int n)
{
    if (a.size() == 0 || a[a.size() - 1] <= n)
    {
        a.push_back(n);
        return;
    }
    int val = a[a.size() - 1];
    a.pop_back();
    insert(a, n);
    a.push_back(val);
}
void sort(vector<int> &v)
{
    if (v.size() == 1)
    {
        return;
    }
    // int val=v[v.size()-1];
    int val = v[v.size() - 1];
    v.pop_back();
    sort(v);
    insert(v, val);
}

int main()
{
    vector<int> a = {2, 7, 5, 3, 9, 1};
    // insert(a,2);
    sort(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}