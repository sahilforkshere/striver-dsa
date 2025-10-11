#include <bits/stdc++.h>
using namespace std;

    void sortColors(vector<int>& a) {
    int n = a.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (a[mid] == 0){
            swap(a[low], a[mid]);
        low++;
        mid++;
        }
        if (a[mid] == 1){
            mid++;
        }
        if (a[mid] == 2){
            swap(a[mid],a[high]);
        
        high--;
        }
    }





    }

 
int main()
{
    vector<int> a={1,0,0,2,1,0,2,1,1,2,2,0,1};
    sortColors(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    

    return 0;
}