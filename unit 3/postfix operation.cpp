#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    bool isFull() { return (top == MAX - 1); }
    bool isEmpty() { return (top == -1); }
    
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

int evaluatePostfix(char* exp) {
    Stack stack;
    for (int i = 0; exp[i]; ++i) {
        if (isdigit(exp[i])) {
            stack.push(exp[i] - '0');
        }
        else {
            int val1 = stack.pop();
            int val2 = stack.pop();
            switch (exp[i]) {
                case '+': stack.push(val2 + val1); break;
                case '-': stack.push(val2 - val1); break;
                case '*': stack.push(val2 * val1); break;
                case '/': stack.push(val2 / val1); break;
            }
        }
    }
    return stack.pop();
}

int main() {
    char exp[MAX];
    cout << "Enter a postfix expression: ";
    cin >> exp;
    cout << "Result: " << evaluatePostfix(exp) << endl;
    return 0;
}
