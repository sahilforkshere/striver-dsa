#include<bits/stdc++.h>
using namespace std;
void tower(int n,char s,char h,char d){
    if(n==0){
            return;
    }
   tower(n-1,s,d,h);
   cout<<s<<"->"<<d;
   tower(n-1,h,s,d);
   return;

}
int main()
{
    int n;
    cout<<"Enter no. of disks"<<" ";
    cin>>n;
    tower(n,'A','B','C');
 return 0;
}