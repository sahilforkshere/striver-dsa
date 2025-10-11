#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <vector>
#include <iostream>

class Node {
public:
    int data;
    Node *next;

    explicit Node(int value) : data(value), next(nullptr) { }
};

// Convert vector to linked list (returns head)
inline Node* vectorToLinkedList(const std::vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Get length of linked list
inline int length(Node *head) {
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        ++cnt;
    }
    return cnt;
}

// Search for a value in the linked list. Returns true if found, else false.
inline bool contains(Node *head, int val) {
    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Reverse the linked list (iterative method)
inline Node* reverseList(Node *head) {
    Node *prev = nullptr;
    Node *curr = head;
    while (curr != nullptr) {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev; // new head
}

// Optional: print the list (for debugging)
inline void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next) std::cout << " -> ";
        temp = temp->next;
    }
    std::cout << "\n";
}

// Optional: free the nodes to avoid memory leak
inline void freeList(Node *head) {
    Node *cur = head;
    while (cur) {
        Node *nxt = cur->next;
        delete cur;
        cur = nxt;
    }
}

#endif // LINKED_LIST_HPP
