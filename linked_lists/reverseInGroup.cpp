#include <bits/stdc++.h>
#include "linked_list.hpp"
using namespace std;

Node *reverseInRange(Node *head, Node *start, Node *end) {
    if (head == nullptr || start == nullptr || end == nullptr) {
        return head;
    }
    if (start == end) {
        return head;
    }
    // find node before `start`
    Node *beforeStart = nullptr;
    if (head != start) {
        beforeStart = head;
        while (beforeStart && beforeStart->next != start) {
            beforeStart = beforeStart->next;
        }
    } 

    Node *afterEnd = end->next;

    // Reverse the sublist
    Node *prev = nullptr;
    Node *curr = start;
    Node *nextNode = nullptr;
    while (curr != afterEnd) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Connect back
    if (beforeStart) {
        beforeStart->next = prev;
    } else {
        head = prev;
    }
    // `start` is then the tail of reversed part
    start->next = afterEnd;

    return head;
}


int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = vectorToLinkedList(a);
   // head = rotateRight(head, 2);
   head=reverseInRange(head,head->next,head->next->next->next->next);
    printList(head);
    return 0;
}