#include <iostream>
#include <cstring>

class Queue {
private:
    static const int MAX_SIZE = 100;
    char* data[MAX_SIZE];
    int front;
    int rear;
    int size;

public:
    Queue() : front(0), rear(-1), size(0) {}

    ~Queue() {
        clear();
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == MAX_SIZE;
    }

    void enqueue(const char* item) {
        if (isFull()) {
            std::cerr << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        data[rear] = new char[strlen(item) + 1];
        strcpy(data[rear], item);
        ++size;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        delete[] data[front];
        front = (front + 1) % MAX_SIZE;
        --size;
    }

    const char* frontElement() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty." << std::endl;
            return nullptr;
        }
        return data[front];
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue charQueue;

    charQueue.enqueue("Hello");
    charQueue.enqueue("World");

    std::cout << "Front element: " << charQueue.frontElement() << std::endl;

    charQueue.dequeue();

    std::cout << "Front element after dequeue: " << charQueue.frontElement() << std::endl;

    charQueue.clear();

    return 0;
}
