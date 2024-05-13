#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList() : head(nullptr) {}
    ~DoubleLinkedList();
    void append(int val);
    void reverse();
    void display();
    void removeElem(int val);
};

void DoubleLinkedList::append(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void DoubleLinkedList::reverse() {
    Node* temp = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }
}

void DoubleLinkedList::removeElem(int val) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == val) {
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next; // Update head if first element is removed
            }

            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }

            Node* toDelete = temp;
            temp = temp->next; // Move temp to next node before deletion

            delete toDelete;
            return;
        } else {
            temp = temp->next;
        }
    }

    cout << "Element not found" << endl;
}

void DoubleLinkedList::display() {
    Node* temp = head;
    cout << "[ ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "]" << endl;
}

DoubleLinkedList::~DoubleLinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

int main() {
    DoubleLinkedList myList;
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);

    cout << "Original list: ";
    myList.display();  // Output: [ 1 2 3 4 ]

    myList.removeElem(4);
    cout << "List after removing 4: ";
    myList.display();  // Output: [ 1 2 3 ]

    myList.reverse();
    cout << "Reversed list: ";
    myList.display();  // Output: [ 3 2 1 ]

    myList.append(5);
    cout << "List after appending 5: ";
    myList.display();  // Output: [ 3 2 1 5 ]

    return 0;
}
