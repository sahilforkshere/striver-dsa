#include <bits/stdc++.h>
using namespace std;
void Merge(int *arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
     
    }
       while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <=high; i++)
        {
         arr[i]=temp[i-low];
        }
        
}

void MergeSort(int *arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
}
int main()
{
    int arr[9] = {3, 5, 4, 7, 1, 3, 0, 2, 4};
    cout<<"before sort"<<endl;
   for (int i = 0; i < 9; i++)
   {
    cout<<arr[i]<<" ";

   }

   cout<<"after sort"<< endl;
   MergeSort(arr,0,8);
   for (int i = 0; i < 9; i++)
   {
    cout<<arr[i]<<" ";
   }
   
   
    return 0;
}