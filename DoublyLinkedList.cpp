#include<iostream>
using namespace std;

// Class defining the structure of each node
class Node {
public:
    int data;
    Node* next;   // Pointer to the next node
    Node* prev;   // Pointer to the previous node

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Class defining the Doubly Linked List
class DoublyLinkedList {
public:
    Node* head; // Pointer to the first node
    Node* tail; // Pointer to the last node

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // ⭐ Operation 1: Insert a new node at the beginning (Prepending)
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        // Case 1: List is empty
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            cout << "Inserted " << val << " at the beginning (list was empty)." << endl;
            return;
        }

        // Case 2: List is NOT empty
        // 1. New node's next points to the current head
        newNode->next = head;
        
        // 2. Current head's prev points back to the new node
        head->prev = newNode;
        
        // 3. Update the head pointer
        head = newNode;

        cout << "Inserted " << val << " at the beginning." << endl;
    }

    // ⭐ Operation 2: Delete the head node
    void deleteHead() {
        if (head == nullptr) {
            cout << "Deletion failed: The list is empty." << endl;
            return;
        }

        // Only one node in the list
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
            cout << "Deleted the only node in the list." << endl;
            return;
        }
        
        // Two or more nodes
        Node* temp = head;
        head = head->next;
        head->prev = nullptr; // The new head has no previous node
        delete temp;

        cout << "Deleted the head node." << endl;
    }
    
    // ⭐ Operation 3: Traversal (Display Forward)
    void displayForward() {
        Node* current = head;
        cout << "Forward List: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // ⭐ Operation 4: Traversal (Display Backward)
    void displayBackward() {
        Node* current = tail;
        cout << "Backward List: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->prev != nullptr) {
                cout << " <-> ";
            }
            current = current->prev;
        }
        cout << endl;
    }
    
    // 🧹 Destructor to free memory when the list object is destroyed
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    DoublyLinkedList dll;
    
    // --- INSERTION ---
    cout << "--- INSERTION ---" << endl;
    dll.insertAtBeginning(30); // List: 30
    dll.insertAtBeginning(20); // List: 20 <-> 30
    dll.insertAtBeginning(10); // List: 10 <-> 20 <-> 30
    
    cout << "\n--- CURRENT LIST STATE ---" << endl;
    dll.displayForward(); 
    dll.displayBackward(); 

    // --- DELETION ---
    cout << "\n--- DELETION (HEAD) ---" << endl;
    dll.deleteHead(); // Deletes 10. List is now 20 <-> 30
    dll.displayForward();

    dll.deleteHead(); // Deletes 20. List is now 30
    dll.displayForward();

    dll.deleteHead(); // Deletes 30. List is now empty
    dll.displayForward();
    
    dll.deleteHead(); // Test deletion on empty list
    
    return 0;
}