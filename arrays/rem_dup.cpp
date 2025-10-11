#include <bits/stdc++.h>

using namespace std;

int rem_dup(vector<int> &a, int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] != a[i])
        {
            i++;
            a[i] = a[j];
        }
    }

    return i + 1;
}

int main()
{
    vector<int> a = {1, 1, 2, 2, 3, 3, 3};
    int uniqueCount = rem_dup(a, a.size());
    for (int k = 0; k < uniqueCount; k++)
    {
        cout << a[k] << " ";
    }

    return 0;
}