#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList
{
    private:
    Node* head;
    public:
    CircularLinkedList():head(nullptr) {}
    void append(int val);
    void display();
    void reverse();
};

void CircularLinkedList::append(int val)
{
    Node* newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
    }
   
    Node* temp = head;
    while (temp->next != head)
    { // Find the last node
        temp = temp->next;
    }
   
    temp->next = newNode;
    newNode->next = head;
}

void CircularLinkedList::reverse()
{
    if(head == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }
   
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    // Node *last = head;
   
    // Proceed with reversal as in a typical singly linked list,
    // but you have to deal with circular nature by adjusting the last node.
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head); // In a circular list, we end where we started.
   
    // Adjusting the circular nature after reversal
    head->next = prev;
    head = prev;
}

void CircularLinkedList::display()
{
    Node* temp = head;
   
    if(temp == nullptr)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"[ ";
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<"]"<<endl;
}

int main()
{
    CircularLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.append(4);
    cout<<"Original list: ";
    mylist.display();
    mylist.reverse();
    cout<<"Reverse List: ";
    mylist.display();
    mylist.append(5);
    cout<<"List After Reverse: ";
    mylist.display();
}