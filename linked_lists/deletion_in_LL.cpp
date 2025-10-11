#include "linked_list.hpp"
#include<bits/stdc++.h>
using namespace std;
Node* deleteHead(Node* head){
    if(head==NULL) return head;
    Node*temp=head;
    head=head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node*head){
    if(head==NULL|| head->next==NULL){
        return NULL;
    }
    Node*temp=head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=NULL;
    return head;
    
}

Node* deleteKth(Node*head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
       return deleteHead(head);
    }
    
  int count=0;
 Node* prev=nullptr;
  Node*curr=head;
    

  while (curr!=NULL )
  {
        count++;
        if(count==k){
            prev->next=prev->next->next;
             free(curr);
            break;
        }
    prev=curr;
    curr=curr->next;

    
  }
 
 
  
    return head;
    
}


Node* deleteEl(Node*head,int val){
    if(head==NULL){
        return head;
    }
    if(head->data==val){
       return deleteHead(head);
    }
    
  
 Node* prev=nullptr;
  Node*curr=head;
    

  while (curr!=NULL )
  {
       
        if(curr->data==val){
            prev->next=prev->next->next;
             free(curr);
            break;
        }
    prev=curr;
    curr=curr->next;

    
  }
 
 
  
    return head;
    
}

// void InsertHead(Node* head,int val){
//     Node*temp= new Node(5);
//     temp->next=head;
//     temp=head;
// }
int main()
{
    vector <int> arr={9,7,11,10,6};
    Node* head=vectorToLinkedList(arr);
//    head= deleteHead(head);
// head=deleteTail(head);
head=deleteKth(head,4);
    printList(head);

    

 return 0;
}