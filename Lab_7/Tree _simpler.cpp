#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(string n) : name(n) {}
};

struct Tree {
    Node* root = nullptr;

    void add_root(string name) { root = new Node(name); }
    void add_left(Node* parent, string name) { parent->left = new Node(name); }
    void add_right(Node* parent, string name) { parent->right = new Node(name); }
};

int main() {
    Tree t;
    t.add_root("A");
    t.add_left(t.root, "B");
    t.add_right(t.root, "C");
    t.add_left(t.root->left, "D");
    t.add_right(t.root->left, "E");
    t.add_left(t.root->right, "F");
    t.add_right(t.root->right, "G");

    cout << "Root: " << t.root->name << endl
         << "Left child of root: " << t.root->left->name << endl
         << "Right child of root: " << t.root->right->name << endl
         << "Left child of B: " << t.root->left->left->name << endl
         << "Right child of B: " << t.root->left->right->name << endl
         << "Left child of C: " << t.root->right->left->name << endl
         << "Right child of C: " << t.root->right->right->name << endl;

    return 0;
}
