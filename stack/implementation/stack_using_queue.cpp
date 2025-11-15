// stack using  queues
#include <bits/stdc++.h>
using namespace std;
queue<int> q;
void push(int x)
{
    //rotate the queue before inserting

    q.push(x);
    for (int i=0;i<q.size();i++)
    {
        q.push(q.front());
        q.pop();
    }
return;
}
void pop()
{
    q.pop();
}
int top()
{
    return q.front();
}



int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    //cout<<q.size();


    return 0;
}

