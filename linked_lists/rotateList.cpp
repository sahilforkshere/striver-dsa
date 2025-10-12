#include <bits/stdc++.h>
#include "linked_list.hpp"
using namespace std;

// Node *reverseList(Node *head)
// {
//     Node *prev = nullptr;
//     Node *curr = head;
//     while (curr != nullptr)
//     {
//         Node *nxt = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = nxt;
//     }
//     return prev;
// }

Node *rotateRight(Node *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;

    // 1. compute length
    int n = 0;
    Node *p = head;
    while (p)
    {
        n++;
        p = p->next;
    }

    k = k % n; // if k >= n, reduce
    if (k == 0)
        return head; // no rotation needed

    // 2. reverse the whole list
    Node *revHead = reverseList(head);

    // 3. find tail of reversed list
    Node *tailRev = revHead;
    while (tailRev->next)
    {
        tailRev = tailRev->next;
    }

    // 4. move first k nodes of revHead to just after tailRev in reversed list
    Node *curr = revHead;
    Node *tempTail = tailRev; // where to append

    // We need to detach first k nodes
    Node *newFront = revHead; // this will move as we detach
    Node *afterK = nullptr;   // node after the first k

    // Move through the first k nodes
    for (int i = 1; i <= k; i++)
    {
        Node *nextNode = newFront->next;
        // detach newFront
        newFront->next = nullptr;
        // append it to the tail
        tempTail->next = newFront;
        tempTail = tempTail->next;
        // advance newFront
        newFront = nextNode;
    }
    // after this, `newFront` is the node just after the first k in the reversed list

    // 5. now revHead should start from newFront (if newFront!=nullptr)
    // Because we've pulled out those k nodes
    revHead = newFront;

    // 6. reverse again to restore correct order
    Node *result = reverseList(revHead);

    return result;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = vectorToLinkedList(a);
    head=rotateRight(head,2);
    printList(head);
    return 0;
}