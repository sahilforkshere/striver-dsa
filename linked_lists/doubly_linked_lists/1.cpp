#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void printList(Node *head)
{
    Node *p = head;
    while (p)
    {
        cout << p->data;
        if (p->next)
            cout << " -> ";
        p = p->next;
    }
    cout << "\n";
}

void printListBackward(Node *head)
{
    if (!head)
    {
        cout << "\n";
        return;
    }
    Node *p = head;
    while (p->next)
        p = p->next; // go to tail
    while (p)
    {
        cout << p->data;
        if (p->back)
            cout << " -> ";
        p = p->back;
    }
    cout << "\n";
}

Node *converttoDLL(vector<int> a)
{
    Node *head = new Node(a[0]);
    Node *prev = head;

    for (int i = 1; i < (int)a.size(); i++)
    {
        Node *temp = new Node(a[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }

    return head;
}

int main()
{
    vector<int> arr = {3, 1, 5, 9};
    Node *head = converttoDLL(arr);
    printList(head);
    cout << "\n";
    printListBackward(head);
    return 0;
}