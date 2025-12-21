#include <bits/stdc++.h>
using namespace std;
vector<int> previousSmaller(vector<int> &v)
{
    vector<int> result;
    stack<int> s;
   for (int i = 0; i < v.size(); i++)
   {
       while (!s.empty() && s.top()>=v[i])
       {
           s.pop();
       }
       if (s.empty())
       {
           result.push_back(-1);
       }
      else
      {
          result.push_back(s.top());
      }

       s.push(v[i]);


   }
    return  result;
}
int main()
{
    vector<int> v={8,3,6,12,10,7};
    vector<int> ans=previousSmaller(v);
    for (int  i: ans)
    {
        cout<<i<<" ";

    }

    return 0;
}
