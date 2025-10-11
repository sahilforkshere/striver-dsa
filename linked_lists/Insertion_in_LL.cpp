#include "linked_list.hpp"
#include<bits/stdc++.h>
using namespace std;

Node* InsertHead(Node* head,int val){
    Node*temp= new Node(val);
    temp->next=head;
  return temp;
}

Node* InsertTail(Node*head,int val){
    Node* newNode= new Node(val);
    Node* temp= head;
    while (temp->next!=NULL )
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=NULL;
    return head;
}

Node* InsertAfterKthPos(Node* head, int k,int val){
    Node* newNode= new Node(val);
    int count=0;
    Node *temp=head;
    while (temp!=NULL)
    {
       count++;
       if(count==k){
          newNode->next=temp->next;
        temp->next=newNode;
      
       }
       temp=temp->next;
    }
    
    return head;
}
Node* InsertAtK(Node* head, int k,int val){
    if(head==NULL){
        if (k==1)
        {
            return new Node(val);
        }
        else{
            return head;
        }
        


    }

    if(k==1){
        return InsertHead(head,val);
    }
    Node* newNode= new Node(val);
    int count=0;
    Node *temp=head;
    while (temp!=NULL)
    {
       count++;
       if(count==k-1){
          newNode->next=temp->next;
        temp->next=newNode;
      
       }
       temp=temp->next;
    }
    
    return head;
}

Node* InsertBeforeValue(Node* head, int valBefore,int val){
    if(head==NULL){
      return NULL;
        


    }

    if(head->data==valBefore){
       Node* newNode= new Node(val);
       newNode->next=head;
       return newNode;

    }
   

    Node *temp=head;
    while (temp->next!=NULL)
    {
     
       if(temp->next->data==valBefore){
         Node* newNode= new Node(val);
      
        temp->next=newNode;
        break;
      
       }
       temp=temp->next;
    }
    
    return head;
}
int main()
{
        vector <int> arr={9,7,11,10,6};
    Node* head=vectorToLinkedList(arr);
//    head= InsertHead(head,4);
// head=InsertTail(head,1);

// head=InsertAtK(head,3,19);
head=InsertBeforeValue(head,11,22);

    printList(head);
 return 0;
}