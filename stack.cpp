#include <iostream>

using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Stack implementation using linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int topValue() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Or throw an exception
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element of stack: " << s.topValue() << endl;
    s.pop();
    cout << "Top element after popping: " << s.topValue() << endl;

    return 0;
}
