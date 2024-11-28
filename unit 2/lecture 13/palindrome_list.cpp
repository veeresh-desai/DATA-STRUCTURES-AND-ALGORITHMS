// You are using GCC
#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;

void insertAtEnd(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

bool isPalindrome() {
    if (head == nullptr) {
        return true;  // An empty list is a palindrome
    }

    Node* start = head;
    Node* end = tail;

    while (start != end && start->prev != end) {
        if (start->data != end->data) {
            return false;
        }
        start = start->next;
        end = end->prev;
    }
    
    return true;
    
    
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        insertAtEnd(data);
    }

    if (isPalindrome()) {
        std::cout << "The patient's medical history is a palindrome" << std::endl;
    } else {
        std::cout << "The patient's medical history is not a palindrome" << std::endl;
    }

    return 0;
}