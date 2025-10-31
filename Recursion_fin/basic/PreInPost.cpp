#include<bits/stdc++.h>
using namespace std;
void PreInPost(int n){
    if (n==0)
    {
        return ;
    }
    cout<<"Pre \t"<<n;
    PreInPost(n-1);
    cout<< "In \t"<<n;
    PreInPost(n-1);
    cout<<"Post \t"<<n;
    return;
    
}
int main()
{
    int n;
    cout<<"Enter a number"<<" ";
    cin>>n;
    PreInPost(n);
 return 0;
}