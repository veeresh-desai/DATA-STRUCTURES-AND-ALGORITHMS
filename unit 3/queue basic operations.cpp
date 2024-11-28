#include <iostream>
using namespace std;

class Queue {
private:
    int rear, front, size;
    int arr[20];
public:
    Queue() {
        rear = -1;
        front = 0;
        size = 0;
    }

    void enque(int item) {
        if (size == 20) {
            cout << "Overflow" << endl;
        } else {
            arr[++rear] = item;
            size++;
        }
    }

    void deque() {
        if (size == 0) {
            cout << "Underflow" << endl;
        } else {
            cout << arr[front] << " dequeued" << endl;
            front++;
            size--;
        }
    }

    void getfront() {
        if (size == 0) {
            cout << "Underflow" << endl;
        } else {
            cout << arr[front] << endl;
        }
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
        } else {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;

    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.display();
    cout << endl;

    q.deque();
    q.deque();
    q.deque();

    q.getfront();
    cout << endl;

    q.display();
    cout << endl;

    return 0;
}
