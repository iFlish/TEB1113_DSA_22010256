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

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    void insert_node(std::string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void delete_node(std::string nameToDelete) {
        if (head == nullptr) {
            std::cout << "Senarai kosong. Tidak boleh padam." << std::endl;
            return;
        }

        if (head->name == nameToDelete) {
            Node* temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->name != nameToDelete) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Nod dengan nama '" << nameToDelete << "' tidak dijumpai." << std::endl;
            return;
        }

        previous->next = current->next;

        if (current == tail) {
            tail = previous;
        }

        delete current;
    }

    void display_list() {
        if (head == nullptr) {
            std::cout << "Senarai kosong." << std::endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            std::cout << current->name << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList std_names;

    std::cout << "--- Keadaan awal ---" << std::endl;
    std_names.display_list();

    std_names.insert_node("Amin");
    std_names.insert_node("Siti");
    std_names.insert_node("Zul");
    std_names.insert_node("Farah");

    std::cout << "\n--- Senarai selepas masukkan (Amin, Siti, Zul, Farah) ---" << std::endl;
    std_names.display_list();

    std_names.delete_node("Zul");
    std::cout << "\n--- Senarai selepas padam 'Zul' ---" << std::endl;
    std_names.display_list();

    std_names.delete_node("Amin");
    std::cout << "\n--- Senarai selepas padam 'Amin' (kepala) ---" << std::endl;
    std_names.display_list();

    std_names.delete_node("Farah");
    std::cout << "\n--- Senarai selepas padam 'Farah' (ekor) ---" << std::endl;
    std_names.display_list();

    std_names.delete_node("Hafiz");
    std::cout << "\n--- Senarai selepas cuba padam 'Hafiz' ---" << std::endl;
    std_names.display_list();

    std_names.delete_node("Siti");
    std::cout << "\n--- Senarai selepas padam 'Siti' (nod terakhir) ---" << std::endl;
    std_names.display_list();

    std_names.delete_node("Azman");
    std::cout << "\n--- Senarai selepas cuba padam dari senarai kosong ---" << std::endl;
    std_names.display_list();

    return 0;
}
