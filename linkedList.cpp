#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
    private:
    Node* head;
    public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    void display();
    void append(int val);
    void reverse();
    void removeElem(int val);
};

void LinkedList::append(int val)
{
    Node *newNode = new Node(val);
    if(head==nullptr){
        head = newNode;
        return;
    }
   
    Node* Last = head;

    while(Last->next != nullptr)
        Last = Last->next;

    Last->next = newNode;
}

void LinkedList::reverse()
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    while (curr != nullptr){
        next = curr->next;  // Store next node
        curr->next = prev;  // Reverse current node's pointer
        prev = curr;        // Move pointers one position ahead
        curr = next;
    }
    head = prev;
}

void LinkedList::display()
{
    Node* temp = head;
    cout<<"[ ";
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "]"<<endl;
}

void LinkedList::removeElem(int val)
{
    Node *temp = head;
    Node *prev = nullptr;
   
    if(temp != nullptr && temp->data == val) {
        head = temp->next;
        delete temp;
        return;
    }
   
    while(temp != nullptr && temp->data == val){
        prev = temp;
        temp = temp->next;
    }
   
    if(temp == nullptr) return;
   
    prev->next = temp->next;
    delete temp;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

int main()
{
    LinkedList myList;
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);

    cout << "Original list: ";
    myList.display(); // Output: [ 1 2 3 4 ]

    myList.reverse();

    cout << "Reversed list: ";
    myList.display(); // Output: [ 4 3 2 1 ]
   
    cout << "List after Reverse, adding element: ";
    myList.append(5);
    myList.display(); // Output: [ 4 3 2 1 5 ]
    
    cout << "List after removing elements: ";
    myList.removeElem(4);
    myList.display(); // Output: [ 3 2 1 5 ]
   
    return 0;
}