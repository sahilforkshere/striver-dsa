//leetcode 1685

#include<bits/stdc++.h>
using namespace std;
vector <int>  getAbsSumDiff(vector<int> &a){
    int n=a.size();
    vector <int> res(n,0);
    vector <int> prefixSum(n,0);

    int sum=0;
    for (int i = 0; i < n; i++)
    {
          sum += a[i];
            prefixSum[i] = sum;
    }

    for (int i = 0; i < n; i++)
    {
           res[i] =
                ((a[i] * i - (prefixSum[i] - a[i])) +
                 ((prefixSum[n - 1] - prefixSum[i]) - (a[i] * (n - i - 1))));
    }
    return res;
    
    
}
int main()

{
    vector <int> a={1,4,6,8,10};
    vector <int> ans=getAbsSumDiff(a);
 for (int i = 0; i < ans.size(); i++)
 {
    cout <<ans[i]<<" ";
 }
 
 //   cout<< ans[0];
    
    

 
    return 0;
}