#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *conArrtoLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int length(Node *head)
{
    int cnt = 0;

    Node *temp = head; //TRAVERSAL ALWAYS COPY

    while (temp)
    {
      
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int search (Node*head,int val){
  Node *temp = head;

    while (temp)
    {
        if (temp->data==val)
        {
            return 1;
        }
        
      
        temp = temp->next;
       
    }
    return 0;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    //    Node y=Node(arr[0],nullptr);
    //    cout<<y.next;
    Node *head = conArrtoLL(arr);

    // Node *temp = head;

    // while (temp)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }

    int ans= length(head);
    cout<<ans<<"\n";
    int pr=search(head,5);
    cout<<pr;

    return 0;
}