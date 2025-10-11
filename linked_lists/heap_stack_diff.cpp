#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void createNodes() {
    // Stack allocation
    Node stackNode(10);
    std::cout << "Stack Node Data: " << stackNode.data << std::endl;

    // Heap allocation
    Node* heapNode = new Node(20);
    std::cout << "Heap Node Data: " << heapNode->data << std::endl;

    // Remember to delete heap-allocated memory to avoid memory leaks
    delete heapNode;
}

int main() {
    createNodes();
    return 0;
}
