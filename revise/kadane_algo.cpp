#include<bits/stdc++.h>
using namespace std;
  vector <int> subArrayWithMax(vector <int> &a){
    int sum=0;
    int maxi=INT_MIN;
    vector <int> newArr;

    for (int i = 0; i < a.size(); i++)
    {
        sum+=a[i];
        newArr.push_back(a[i]);
        if (sum>maxi)
        {
            maxi=sum;
        }

        else if (sum<0)
        {
            sum=0;
            newArr.clear();
        }

        
        
        
    }
    return  newArr;
    
  }

int main()
{
    vector <int> a={ 0,-1,-3,-4,-2,-6,-3,-1,9,2,3,-1,3};
    vector <int> ansArr=subArrayWithMax(a);
    for (int i = 0; i < ansArr.size(); i++)
    {
        cout<<ansArr[i]<<" ";
    }
    



 return 0;
}