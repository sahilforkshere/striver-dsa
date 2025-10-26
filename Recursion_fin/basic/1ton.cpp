#include<bits/stdc++.h>
using namespace std;

void print1toN(int n,int f){
    if(n>f){
        return ;
    }
 

    print1toN(n+1,f);
      cout<<n<<"\n";
}

void printN(int n){
    if (n==1)
    {
        cout<<1<<" ";
        return;
    }
    printN(n-1);
    cout<<n<<" ";
    
}

int main()
{
    //print1toN(1,7);
    printN(8);

 return 0;
}