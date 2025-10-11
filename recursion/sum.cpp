#include<iostream>
using namespace std;

 int add(int n){
    if (n==0)
    {
        return 0;
    }
     return n + add(n-1);
    
 }

int main()
{
    int n;
    cout<<"Enter a number \n";
    cin>>n;
  int res=  add(n);
  cout<<res;
 return 0;
}