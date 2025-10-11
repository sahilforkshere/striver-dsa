#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEnd(vector<int> &a)
{
    int n = a.size();
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    for (int i = j+1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
}
int main()
{
    vector<int> a = {2, 1, 0, 4, 0, 0, 3, 0, 1};
    moveZeroesToEnd(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}