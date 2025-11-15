#include <bits/stdc++.h>
using namespace std;
    stack<int> s1,s2;
void push(int x)
{
    //step 2
    while (s1.size()!=0)
    {
        s2.push(s1.top());
        s1.pop();

    }
    s1.push(x);

    while (s2.size()!=0)
    {
        s1.push(s2.top());
        s2.pop();

    }

}

int top()
{
    return s1.top();
}

void pop()
{
    s1.pop();
}

// making pop and top expensive

void pop2()
{
    if (!s2.empty())
    {
        s2.pop();
    }
    else
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
       s2.pop();

    }


}

int top2()
{
    if (!s2.empty())
    {
        s2.pop();
    }
    else
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        return  s2.top();
    }
}

int main()
{
    return 0;
}

