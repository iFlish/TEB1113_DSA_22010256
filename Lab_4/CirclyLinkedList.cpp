#include <iostream>
#include <string>

class Node {
public:
    std::string name;
    Node* next;

    Node(std::string nodeName) : name(nodeName), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor for proper cleanup of circular linked list
    ~LinkedList() {
        if (head == nullptr)
            return;

        Node* current = head;
        do {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
        tail = nullptr;
    }

    // Insert a node at the end of the circular linked list
    void insert_node(std::string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head; // Make it circular
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Maintain circular link
        }
    }

    // Display the circular linked list
    // Display the circular linked list with loop back indication
void display_list() {
    if (head == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node* current = head;
    std::cout << "[HEAD] ";
    do {
        std::cout << current->name << " -> ";
        current = current->next;
    } while (current != head);

    std::cout << head->name  << std::endl;
}

};

int main() {
    LinkedList studentNames;

    std::cout << "--- Initial State ---" << std::endl;
    studentNames.display_list();

    studentNames.insert_node("Amin");
    studentNames.insert_node("Siti");
    studentNames.insert_node("Zul");
    studentNames.insert_node("Farah");

    std::cout << "\n--- List after inserting (Amin, Siti, Zul, Farah) ---" << std::endl;
    studentNames.display_list();

    return 0;
}
