#include <iostream>
#include <string>

#define MAX_SIZE 100

class Queue {
private:
    std::string data[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() : front(0), rear(0) {}

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return rear == MAX_SIZE;
    }

    void enqueue(std::string name) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot add '" << name << "'." << std::endl;
            return;
        }
        data[rear++] = name;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot remove any item." << std::endl;
            return;
        }

        std::cout << "Removing: " << data[front] << std::endl;
        front++;

        if (front == rear) {
            front = rear = 0;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        std::cout << "Queue contents: ";
        for (int i = front; i < rear; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue studentQueue;

    std::cout << "--- Initial State ---" << std::endl;
    studentQueue.display();

    studentQueue.enqueue("Amin");
    studentQueue.enqueue("Siti");
    studentQueue.enqueue("Zul");
    studentQueue.enqueue("Farah");

    std::cout << "\n--- After enqueue (Amin, Siti, Zul, Farah) ---" << std::endl;
    studentQueue.display();

    studentQueue.dequeue();
    std::cout << "\n--- After removing one (Amin) ---" << std::endl;
    studentQueue.display();

    studentQueue.dequeue();
    std::cout << "\n--- After removing one more (Siti) ---" << std::endl;
    studentQueue.display();

    studentQueue.dequeue();
    studentQueue.dequeue();
    std::cout << "\n--- After removing all ---" << std::endl;
    studentQueue.display();

    studentQueue.dequeue();

    return 0;
}
