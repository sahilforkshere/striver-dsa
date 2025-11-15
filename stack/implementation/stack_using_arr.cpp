#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int st[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        cout << "Stack OverFlow";
        return;
    }
    st[top++] = x;
}
int peek()
{
    if (top == -1)
    {
        cout << "Stack is Empty";
        return top;
    }
    else
    {
        return st[top];
    }
 
}
   int pop()
    {
        if (top == -1)
        {
            cout << "nothing to pop";
            return top;
        }
        return st[top--];
    }
int main()
{
    return 0;
}