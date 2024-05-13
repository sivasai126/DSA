#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* leftChild;
    Node* rightChild;
    Node(int val) : data(val), leftChild(nullptr), rightChild(nullptr) {}
};

class Btree {
private:
    Node* root;
    void inorderTraversal(Node* node);
    void preOrderTraversal(Node* node);
    void postOrderTraversal(Node* node);
    void levelOrderTraversal(Node* node);

public:
    Btree() : root(nullptr) {}
    ~Btree();
    void insert(int val);
    void displayInorder();
    void displayPreOrder();
    void displayPostOrder();
    void displayLevelOrder();
    void clear(Node* node);
};

Btree::~Btree() {
    clear(root);
}

void Btree::clear(Node* node) {
    if (node != nullptr) {
        clear(node->leftChild);
        clear(node->rightChild);
        delete node;
    }
}

void Btree::insert(int val) {
    Node* tempNode = new Node(val);
    if (root == nullptr) {
        root = tempNode;
    } else {
        Node* current = root;
        Node* parent = nullptr;
        while (true) {
            parent = current;
            if (val < current->data) {
                current = current->leftChild;
                if (current == nullptr) {
                    parent->leftChild = tempNode;
                    return;
                }
            } else {
                current = current->rightChild;
                if (current == nullptr) {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

void Btree::inorderTraversal(Node* node) {
    if (node != nullptr) {
        inorderTraversal(node->leftChild);
        cout << node->data << " ";
        inorderTraversal(node->rightChild);
    }
}

void Btree::preOrderTraversal(Node* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preOrderTraversal(node->leftChild);
        preOrderTraversal(node->rightChild);
    }
}

void Btree::postOrderTraversal(Node* node) {
    if (node != nullptr) {
        postOrderTraversal(node->leftChild);
        postOrderTraversal(node->rightChild);
        cout << node->data << " ";
    }
}

void Btree::levelOrderTraversal(Node* node) {
    if (node == nullptr) return;

    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->leftChild != nullptr)
            q.push(current->leftChild);
        if (current->rightChild != nullptr)
            q.push(current->rightChild);
    }
}

void Btree::displayInorder() {
    inorderTraversal(root);
    cout << endl;
}

void Btree::displayPreOrder() {
    preOrderTraversal(root);
    cout << endl;
}

void Btree::displayPostOrder() {
    postOrderTraversal(root);
    cout << endl;
}

void Btree::displayLevelOrder() {
    levelOrderTraversal(root);
    cout << endl;
}

int main() {
    Btree tree;
    for (int i = 1; i <= 5; i++) {
        tree.insert(i);
    }

    cout << "Inorder traversal: ";
    tree.displayInorder(); // Output: 1 2 3 4 5
    cout << "Preorder traversal: "; 
    tree.displayPreOrder(); // Output: 1 2 3 4 5
    cout << "Postorder traversal: ";
    tree.displayPostOrder(); //Output: 5 4 3 2 1
    cout << "Level order traversal: ";
    tree.displayLevelOrder(); //Output: 1 2 3 4 5
   
    return 0;
}