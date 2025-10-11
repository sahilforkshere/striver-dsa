#include<bits/stdc++.h>
using namespace std;

int fn( int *arr,int low,int high){
    int pivot=low;
    int i=low;
    int j=high;
    while (i<j)
    {
    while (arr[i]<=arr[pivot] && i<=high)
    {
        i++;
    }
    while (arr[j]>arr[pivot] && j>low)
    {
        j--;
    }
    if (i<j)
    {
        swap(arr[i],arr[j]);
    }
          /* code */
    }

    swap(arr[low],arr[j]);
    return j;
    
  

    
    
}
void quickSort(int *arr,int low,int high){
    if (low<high)   
    {
       int  partIndex=fn(arr,low,high);
        quickSort(arr,low,partIndex-1);
        quickSort(arr,partIndex+1,high);
    }
    
}
int main()
{
    int arr[9]={7,2,3,0,1,4,5,2};
    quickSort(arr,0,8);
    for (int i = 0; i < 9; i++)
    {
        cout<<arr[i]<<" ";
    }
    
 return 0;
}