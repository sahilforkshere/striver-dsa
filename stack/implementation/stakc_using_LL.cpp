#include <bits/stdc++.h>
#include "../../linked_list.hpp"
Node * top;
int size=0;

void push(int x)
{
    Node * newNode= new Node(x);
    newNode -> next = top;
    top = newNode;
    size++;

}

int pop()
{
    if (top == NULL)
    {
        cout<<"Stack is Empty"<<endl;
    }
    else
    {
        Node * temp=top;
        top = top -> next;
        delete temp;
        size--;
    }


}


using namespace std;

int main()
{
    Node * head=nullptr;

    return 0;
}

