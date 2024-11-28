#include <iostream>

struct Node {
    char data;
    Node* next;
    
    
    Node(char val){
        data=val;
        next=NULL;
    }
};



void insertAfterPosition(Node* head, int position, char value, int nu=10) {
    Node* newNode = new Node(value);
    
    if (position == 0) {
        newNode->next = head->next;
        head->next = newNode;
        return;
    } else if (position > nu) {
        std::cout << "Invalid position." << std::endl;
        return;
    } else {
        Node* temp = head;
        
        for (int i = 0; i < position && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        return;
    }
}

void displayList(Node* head) {
    Node* current = head->next;  // Skip the dummy head node
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node('\0');  // Dummy head node
    int n;
    char value;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> value;
        insertAfterPosition(head, i, value);
    }

    int position;
    std::cin >> position;

    std::cin >> value;

    insertAfterPosition(head, position, value, n);
    std::cout << "Updated list: ";

    displayList(head);

    deleteList(head);

    return 0;
}
