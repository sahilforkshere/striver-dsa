#include <bits/stdc++.h>
using namespace std;
void rotateByOne(vector<int> &a, int n)
{
    int temp = a[0];
    for (int i = 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    a[n - 1] = temp;
}
int main()
{
    vector<int> arr = {4, 5, 6, 8, 9};
    rotateByOne(arr, arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}