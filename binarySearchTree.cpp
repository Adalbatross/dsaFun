#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return root;
    if (value < root->data) root->left = deleteNode(root->left, value);
    else if (value > root->data) root->right = deleteNode(root->right, value);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;
    
    do {
        cout << "\nBinary Search Tree Menu:";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Postorder Traversal";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 3:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Exiting program...";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice != 6);
    
    return 0;
}
