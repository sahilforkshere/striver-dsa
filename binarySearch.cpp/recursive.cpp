#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector<int> &a, int low, int high, int target)
{
    int mid = (low + high) / 2;

    if (low <= high)
    {
        if (a[mid] > target)
        {
            binarySearch(a, low, mid - 1, target);
        }
        else if (a[mid] < target)
        {
            binarySearch(a, mid + 1, high, target);
        }

        else
        {
            cout <<"Found"<< mid;
        }
    }
  if(low>high){
    cout << "Not found";
  }
}

int main()
{

    int t;
    cout << "Enter which element you want to search";
    cin >> t;
    vector<int> a = {1, 3, 5, 12, 15, 17, 19};
    binarySearch(a, 0, 6, t);

    return 0;
}