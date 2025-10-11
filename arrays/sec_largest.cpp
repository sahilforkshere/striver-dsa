#include <bits/stdc++.h>
using namespace std;
int sLargest(vector<int> &a, int n)
{
    int largest = a[0];
    int secLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            secLargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > secLargest)
        {
            secLargest = a[i];
        }
    }
    return secLargest;
}

int sSmallest(vector<int> a, int n)
{
    int smallest = a[0];
    int secSmallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < smallest)
        {
            secSmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] != smallest && a[i] < secSmallest)
        {
            secSmallest = a[i];
        }
    }

    return secSmallest;
}
bool isSorted(vector<int> &a, int n)
{
    int left = 0;
    int right = 1;
    bool flag = true;
    while (left <= right)
    {
        if (a[left] <= a[right])
        {
            left++;
            right++;
        }

        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
        return true;
}
int main()
{
    vector<int> a = {1, 2, 3, 3, 4, 6};
    int seclargest = sLargest(a, 7);
    int secSmallest = sSmallest(a, 7);
    cout << seclargest << "" << endl;
    cout << secSmallest << " " << endl;
    cout << isSorted(a, 7);

    return 0;
}