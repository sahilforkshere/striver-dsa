#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert at head
void insertHead(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at tail
void insertTail(Node* &head, int val) {
    Node* newNode = new Node(val);

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

// Delete head
void deleteHead(Node* &head) {
    if (!head) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete tail
void deleteTail(Node* &head) {
    if (!head) return;

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

// Search a value
bool searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

// Length of list
int length(Node* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

// Print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Free entire list
void freeList(Node* &head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

#endif
