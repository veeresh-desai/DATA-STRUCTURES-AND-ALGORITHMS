// You are using GCC
#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int capacity;
    int* array;

public:
    Queue(int cap) {
        capacity = cap;
        front = size = 0;
        rear = capacity - 1;
        array = new int[capacity];
    }

    ~Queue() {
        delete[] array;
    }

    bool isFull() {
        return (size == capacity);
    }

    bool isEmpty() {
        return (size == 0);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
        cout << "Helpdesk Ticket ID " << item << " is enqueued." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int item = array[front];
        front = (front + 1) % capacity;
        size--;
        cout << "Dequeued Helpdesk Ticket ID: " << item << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Helpdesk Ticket IDs in the queue are: ";
        for (int i = 0; i < size; i++) {
            cout << array[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue(5);
    int choice, ticketID;

    while (true) {
       cin >> choice;

        switch (choice) {
            case 1:
                cin >> ticketID;
                queue.enqueue(ticketID);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Exiting the program" << endl;
                return 0;
            default:
                cout << "Invalid option." << endl;
        }
    }

    return 0;
}