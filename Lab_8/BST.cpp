#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void insert(string name) {
        root = insert_recursive(root, name);
    }

    Node* insert_recursive(Node* current, string name) {
        if (current == nullptr) {
            return new Node(name);
        }

        if (name < current->name) {
            current->left = insert_recursive(current->left, name);
        } else {
            current->right = insert_recursive(current->right, name);
        }

        return current;
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->name << " ";
        inorder(node->right);
    }
};

int main() {
    BST tree;

    tree.insert("D");
    tree.insert("B");
    tree.insert("F");
    tree.insert("A");
    tree.insert("C");
    tree.insert("E");
    tree.insert("G");

    cout << "In-order traversal of BST: ";
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}
