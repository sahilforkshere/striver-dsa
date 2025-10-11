
#include <bits/stdc++.h>
#include "linked_list.hpp"
using namespace std;
Node* InsertHead(Node* head,int val){
    Node*temp= new Node(val);
    temp->next=head;
  return temp;
}

Node *addOne(Node *head)
{
    Node * revHead=reverseList(head);
    Node *temp = revHead;
    bool carry = true;

    while ( temp!= nullptr)
    {
        if (temp->data == 9)
        {
            temp->data = 0;
        }
        else
        {
            temp->data = (temp->data) + 1;
            carry = !carry;
            break;
        }


        temp = temp->next;
    }
  if (carry)
{
    head=reverseList(revHead);
    head=InsertHead(head,1);
    return head;
}
    
   head= reverseList(revHead);


    return head;
}
// using rec and backtrack
 int addHelper(Node * temp){
    if (temp==nullptr)
    {
        return 1;
    }
    int carry= addHelper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10){
        return 0;
    }
  
    temp->data=0;
    return 1;
    
    
 }

 Node * addOneRec(Node * head){
    int carry=addHelper(head);
    if (carry==1)
    {
        Node * newNode= new Node(1);
        head=InsertHead(head,1);
        return head;
    }
    return head;
    
 }
int main()
{
    vector<int> a = {9,9 };
    Node *head = vectorToLinkedList(a);
   // head=addOne(head);
    head =addOneRec(head);


    printList(head);

    return 0;
}