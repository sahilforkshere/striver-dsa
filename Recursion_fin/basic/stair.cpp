#include<bits/stdc++.h>
using namespace std;

int noOfWays( int n){
    if(n==1 ) return 1;
    if(n==2) return 2;
    int totalWays=noOfWays(n-1)+noOfWays(n-2);
    return totalWays;
}

int main()
{
    int a;
    cout<<"Enter a no."<<" ";
    cin>>a;

    int ans=noOfWays(a);
    cout<<ans;

 return 0;
}