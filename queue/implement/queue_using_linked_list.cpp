#include <iostream>

using namespace std;

// The Node structure, same as in your header
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to check if the queue is empty
bool isEmpty(Node* front) {
    return front == nullptr;
}

// Function to add an item to the REAR of the queue
// We pass front and rear by reference (Node* &)
// because they can change.
void enqueue(Node* &front, Node* &rear, int val) {
    Node* newNode = new Node(val);

    // If the queue is empty, the new node is both front and rear
    if (isEmpty(front)) {
        front = rear = newNode;
        cout << val << " enqueued." << endl;
        return;
    }

    // Otherwise, add the new node to the end (at rear)
    rear->next = newNode;
    // Update the rear pointer to this new node
    rear = newNode;

    cout << val << " enqueued." << endl;
}

// Function to remove an item from the FRONT of the queue
// Pass by reference (Node* &) since both front and
// rear (in one edge case) can change.
void dequeue(Node* &front, Node* &rear) {
    if (isEmpty(front)) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    // Store the old front node to delete it
    Node* temp = front;
    int dequeuedValue = temp->data;

    // Move front to the next node
    front = front->next;

    // IMPORTANT: If front becomes null, the queue is now empty.
    // We must also update rear to null.
    if (front == nullptr) {
        rear = nullptr;
    }

    // Free the memory of the old front node
    delete temp;

    cout << dequeuedValue << " dequeued." << endl;
}

// Function to get the front element without removing it
// We only need to read 'front', so no reference is needed.
int peek(Node* front) {
    if (isEmpty(front)) {
        cout << "Queue is empty." << endl;
        return -1; // Or some other error indicator
    }
    return front->data;
}

// Function to display the queue
// We only need to read, so no reference is needed.
void display(Node* front) {
    if (isEmpty(front)) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;
    cout << "Front -> ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "Rear" << endl;
}

// Function to free all memory at the end
void freeQueue(Node* &front) {
    while (!isEmpty(front)) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

// --- Main function to test the queue ---
int main() {
    // These two pointers represent our queue.
    // They are declared in main() and passed to functions.
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, 10);
    enqueue(front, rear, 20);
    enqueue(front, rear, 30);
    display(front); // Output: Front -> 10 -> 20 -> 30 -> Rear

    cout << "Front element is: " << peek(front) << endl; // Output: 10

    dequeue(front, rear); // Output: 10 dequeued.
    display(front); // Output: Front -> 20 -> 30 -> Rear

    enqueue(front, rear, 40);
    display(front); // Output: Front -> 20 -> 30 -> 40 -> Rear

    dequeue(front, rear); // Output: 20 dequeued.
    dequeue(front, rear); // Output: 30 dequeued.

    cout << "Front element is: " << peek(front) << endl; // Output: 40

    dequeue(front, rear); // Output: 40 dequeued.
    display(front); // Output: Queue is empty.

    // Test empty operations
    dequeue(front, rear); // Output: Queue is empty. Cannot dequeue.

    // Clean up any remaining memory (though our queue is empty now)
    freeQueue(front);
    rear = nullptr; // Good practice

    return 0;
}