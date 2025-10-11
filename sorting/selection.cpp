#include <bits/stdc++.h>
using namespace std;
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 2; i++)
    {
        int min = i;
        for (int j = i; j < n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
          
        }
          swap(arr[min], arr[i]);
    }


    


}



void bubble_sort(int arr[],int n){
    for (int i = n-1; i >=0; i--)
    {
        // optimization bubble sort
        int didSwap=0;
        for (int j = 0; j <=i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                didSwap=1;
            }
            
        }
        if (didSwap==0)
        {
            break;
        }
        
        
    }
    
}
int main()
{
    int arr[5] = {33, 22, 23, 12, 15};
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }
 cout<<"after sorting";
     bubble_sort(arr,5);
for (int i = 0; i < 5; i++)
{
     cout<<arr[i]<<endl;
}

    

    return 0;
}