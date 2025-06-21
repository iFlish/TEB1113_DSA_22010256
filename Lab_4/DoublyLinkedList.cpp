#include <iostream>
#include <string>

class Node {
public:
    std::string name;
    Node* next;
    Node* prev;

    Node(std::string nodeName) : name(nodeName), next(nullptr), prev(nullptr) {}
};

class DoublyCircularLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyCircularLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyCircularLinkedList() {
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

    void insert_node(std::string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void display_list_forward() {
        if (head == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        Node* current = head;
        std::cout << "[HEAD] ";
        do {
            std::cout << current->name << " <-> ";
            current = current->next;
        } while (current != head);
        std::cout << head->name <<  std::endl;
    }

    void display_list_backward() {
        if (tail == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        Node* current = tail;
        std::cout << "[TAIL] ";
        do {
            std::cout << current->name << " <-> ";
            current = current->prev;
        } while (current != tail);
        std::cout << "[TAIL: " << tail->name << "] (circular)" << std::endl;
    }
};

int main() {
    DoublyCircularLinkedList studentNames;

    std::cout << "--- Initial State ---" << std::endl;
    studentNames.display_list_forward();

    studentNames.insert_node("Amin");
    studentNames.insert_node("Siti");
    studentNames.insert_node("Zul");
    studentNames.insert_node("Farah");

    std::cout << "\n--- List Forward ---" << std::endl;
    studentNames.display_list_forward();

    std::cout << "\n--- List Backward ---" << std::endl;
    studentNames.display_list_backward();

    return 0;
}
