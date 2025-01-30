#include <iostream>
using namespace std;

// Node structure for binary search tree (BST)
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// BinarySearchTree class to manage the tree
class BinarySearchTree {
public:
    Node* root;

    // Constructor to initialize the root of the tree
    BinarySearchTree() {
        root = nullptr;
    }

    // Insert a node into the BST
    void insert(int value) {
        root = insertHelper(root, value);
    }

    // Helper function to insert recursively
    Node* insertHelper(Node* node, int value) {
        // If the tree/subtree is empty, create a new node
        if (node == nullptr) {
            return new Node(value);
        }

        
        if (value < node->data) {
            node->left = insertHelper(node->left, value);  // Insert in left subtree if the value is less than the value in the root node
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);  // Insert in right subtree if the value is more than the valur in the root node
        }

        // Return the (unchanged) node pointer
        return node;
    }

    // Inorder Traversal (Left, Root, Right)
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Preorder Traversal (Root, Left, Right)
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Postorder Traversal (Left, Right, Root)
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    // Functions to start traversals from root
    void inorder() { inorder(root); }
    void preorder() { preorder(root); }
    void postorder() { postorder(root); }
};

// Menu-driven function for user interaction
void menu() {
    BinarySearchTree tree;
    int choice, value;

    do {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                cout << value << " is inserted into the binary search tree.\n";
                break;

            case 2:
                cout << "Inorder Traversal: ";
                tree.inorder();  // Inorder traversal
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                tree.preorder();  // Preorder traversal
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                tree.postorder();  // Postorder traversal
                cout << endl;
                break;

            case 5:
                cout << "Exiting the program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    menu();  // Call the menu function to interact with the user
    return 0;
}
