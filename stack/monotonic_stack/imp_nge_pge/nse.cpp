#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> &v)
{
    vector<int> result;
    stack<int> s;
    for (int i=v.size()-1;i>=0;i--)
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

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    vector<int> v={15, 7, 9, 5, 13, 8, 4, 12, 6, 10};
    vector<int> result=nextSmaller(v);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}
