#include <iostream>
using namespace std;

class Node {
public:
    int petCode;
    Node* next;

    Node(int petCode) : petCode(petCode), next(nullptr) {}
};

Node* createNode(int petCode) {
    return new Node(petCode);
}

void printList(Node* head) {
    if (head == nullptr) {
        return;
    }
    
    Node* temp = head;
    do {
        cout << temp->petCode << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

Node* insertAtEnd(Node* head, int newPetCode) {
    Node* newNode = new Node(newPetCode);

    if (head == nullptr) {
        newNode->next = newNode; // Point to itself to form a circular link
        return newNode;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    // Insert new node at the end and link it to the head
    tail->next = newNode;
    newNode->next = head;
    
    return head;
}

Node* removeByCode(Node* head, int petToRemove) {
    if (head == nullptr) {
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // If the node to remove is the head
    if (head->petCode == petToRemove) {
        if (head->next == head) {  // Only one node in the list
            delete head;
            return nullptr;
        }
        
        // Find the last node to link it to the new head
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = head->next;  // Last node points to the new head
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
        return head;
    }

    // Otherwise, find the node to remove
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->petCode != petToRemove);

    // If the node was found, remove it
    if (temp->petCode == petToRemove) {
        prev->next = temp->next;
        delete temp;
    }

    return head;
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;

    // Build the initial circular linked list
    for (int i = 0; i < N; i++) {
        int petCode;
        cin >> petCode;
        head = insertAtEnd(head, petCode);
    }

    int newPetCode, petToRemove;
    cin >> newPetCode;
    cin >> petToRemove;

    // Insert new pet at the end
    head = insertAtEnd(head, newPetCode);
    printList(head);

    // Remove a pet by code
    head = removeByCode(head, petToRemove);
    printList(head);

    return 0;
}
