#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " is pushed onto the stack" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        } else {
            Node* temp = top;
            cout << top->data << " is popped from the stack" << endl;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            Node* temp = top;
            cout << "Elements in the stack: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;
    int choice, value;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting the program" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}