#include <bits/stdc++.h>
using namespace std;

vector< int> pge(vector< int > arr)
{
    stack<int> s;
    vector< int> ans;

    int i =0;
    while (i<arr.size())
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(s.top());
        }

        s.push(i);
        i++;



    }

  //  reverse(ans.begin(),ans.end());
    return ans;


}

int main()
{
    vector <int > v1={4,12,5,3,1,2,5,3,1,2,4,6};
    vector< int> v2=pge(v1);

    for (auto i:v2)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;

    return 0;
}

