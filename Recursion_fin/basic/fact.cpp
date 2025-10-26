#include<bits/stdc++.h>
using namespace std;
int factorial(int a){
    if(a==0 || a==1){
        return 1;
    }
    return a * factorial(a-1);
}
int main()
{
    int ans= factorial(5);
    cout<<ans;  

 return 0;
}