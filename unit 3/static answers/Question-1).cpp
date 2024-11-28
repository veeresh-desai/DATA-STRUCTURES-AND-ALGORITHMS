#include <iostream>
#include <vector>
using namespace std;

class TextEditor {
private:
    vector<char> stack;
    int maxSize;

public:
    TextEditor(int size) : maxSize(size) {}

    void push(char ch) {
        if (stack.size() < maxSize) {
            stack.push_back(ch);
            cout << "Typed character: " << ch << endl;
        } else {
            cout << "Text editor buffer is full. Cannot type more characters." << endl;
        }
    }

    void pop() {
        if (stack.empty()) {
            cout << "Text editor buffer is empty. Nothing to undo." << endl;
        } else {
            char ch = stack.back();
            stack.pop_back();
            cout << "Undo: Removed character " << ch << endl;
        }
    }

    void display() {
        if (stack.empty()) {
            cout << "Text editor buffer is empty." << endl;
        } else {
            cout << "Current text: ";
            for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TextEditor editor(100);
    int choice;
    char ch;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> ch;
                editor.push(ch);
                break;
            case 2:
                editor.pop();
                break;
            case 3:
                editor.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}