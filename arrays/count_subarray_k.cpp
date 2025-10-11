#include<bits/stdc++.h>
using namespace std;
int countSubarray(vector<int> &a,int k){
    int count = 0;
        
        int n = a.size();
        for (int i = 0; i < n; ++i) {
             long long sum = 0;
            for (int j = i; j < n; ++j) {
                
                    sum += a[j];
                
                if (sum ==k) {
                    count++;
                   
                }
            }
        }
        return count;
}
int main()
{
    int k;
    cout<<"Enter the sum\n";
    cin>>k;
    vector <int> a={1,2,3};
    int ans= countSubarray(a,k);
    cout<<ans;
 return 0;
}