#include <bits/stdc++.h>
using namespace std;
void solve(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s, k - 1);
    s.push(temp); 
}
stack<int> deleteMiddle(stack<int> &s, int size)
{
    if (s.size() == 0)
    {
        return s;
    }
    int k = size / 2 + 1;
    solve(s, k);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5); // 5 4 3 2 1
    deleteMiddle(st,5);

    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}