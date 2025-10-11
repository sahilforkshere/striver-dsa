#include<bits/stdc++.h>
using namespace std;
int total(string s){
int n=s.length();
int count =0;
for (int i = 0; i < n; i++)
{
    for (int j = i; j < n; j++)
    {
        count++;
    }
    
}
return count;

}
int main()
{
    string s="sbc";
    int ans=total(s);
    cout<<ans;
 return 0;
}