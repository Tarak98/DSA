#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    // Check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }
    
    // Insert a node at the beginning of the list
    void insertAtHead(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        
        if (isEmpty()) {
            tail = newNode;
        } else {
            head->prev = newNode;
        }
        
        newNode->next = head;
        head = newNode;
    }
    
    // Insert a node at the end of the list
    void insertAtTail(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        
        if (isEmpty()) {
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
        }
        
        tail = newNode;
    }
    
    // Display the list from head to tail
    void displayForward() {
        if (isEmpty()) {
            std::cout << "The list is empty." << std::endl;
        } else {
            Node* current = head;
            std::cout << "List (head to tail): ";
            
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
            
            std::cout << std::endl;
        }
    }
    
    // Display the list from tail to head
    void displayBackward() {
        if (isEmpty()) {
            std::cout << "The list is empty." << std::endl;
        } else {
            Node* current = tail;
            std::cout << "List (tail to head): ";
            
            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->prev;
            }
            
            std::cout << std::endl;
        }
    }
};

int main() {
    DoublyLinkedList myList;
    
    myList.insertAtHead(10);
    myList.insertAtHead(20);
    myList.insertAtTail(30);
    myList.insertAtTail(40);
    
    myList.displayForward();
    myList.displayBackward();
    
    return 0;
}
