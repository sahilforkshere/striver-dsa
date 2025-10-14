#include <bits/stdc++.h>
#include "linked_list.hpp"
using namespace std;

Node *middlep(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *fast = head->next;
    Node *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *mergeTwoLists(Node *l1, Node *l2)
{
    Node *dummyNode = new Node(-1);
    Node *tempdum = dummyNode;
    Node *t1 = l1;
    Node *t2 = l2;
    while (t1 != nullptr && t2 != nullptr)
    {
        int t1val = t1->data;
        int t2val = t2->data;
        if (t1val >= t2val)
        {
            Node *newNode = new Node(t2val);

            tempdum->next = newNode;
            t2 = t2->next;
        }
        else if (t1val < t2val)
        {
            Node *newNode = new Node(t1val);
            tempdum->next = newNode;

            t1 = t1->next;
        }
        tempdum = tempdum->next;
    }
    if (t1)
    {
        tempdum->next = t1;
        t1 = t1->next;
    }
    else if (t2)
    {
        tempdum->next = t2;
        t2 = t2->next;
    }

    dummyNode = dummyNode->next;
    return dummyNode;
}

Node *sortList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *middle = middlep(head);
    Node *rightHead = middle->next;
    middle->next = nullptr;
    Node *leftHead = head;
    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);
    return mergeTwoLists(leftHead, rightHead);
}

int main()
{
    vector<int> a = {8, 5, 1, 6, 3, 2, 4};
    Node *head = vectorToLinkedList(a);
    head=sortList(head);

    printList(head);
    return 0;
}