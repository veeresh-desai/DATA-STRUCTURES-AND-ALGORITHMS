#include <iostream>
using namespace std;

class Node {
public:
    int licensePlate;
    Node* next;

    Node(int licensePlate) : licensePlate(licensePlate), next(nullptr) {}
};

Node* createNode(int licensePlate) {
    return new Node(licensePlate);
}

void deleteByPlate(Node* &head, int plateToRemove) {
    if (head == nullptr) {
        return;
    }

    // If head node itself needs to be removed
    if (head->licensePlate == plateToRemove) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;  // Important to stop further execution
    }

    // Find the node before the one to be deleted
    Node* temp = head;
    while (temp->next != nullptr && temp->next->licensePlate != plateToRemove) {
        temp = temp->next;
    }

    // If node not found
    if (temp->next == nullptr) {
        return;
    }

    // Delete the node
    Node* nodetodel = temp->next;
    temp->next = temp->next->next;
    delete nodetodel;
}

void deleteByPosition(Node* &head, int position) {
    if (head == nullptr) {
        return;
    }

    // If head needs to be removed
    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;  // Stop further execution
    }

    // Find the node before the one to be deleted
    Node* temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // If position is beyond the list length
    if (temp == nullptr || temp->next == nullptr) {
        return;
    }

    // Delete the node
    Node* nodetodel = temp->next;
    temp->next = temp->next->next;
    delete nodetodel;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->licensePlate << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Create the list
    for (int i = 0; i < N; i++) {
        int licensePlate;
        cin >> licensePlate;
        Node* newNode = createNode(licensePlate);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int plateToRemove, positionToRemove;
    cin >> plateToRemove;
    cin >> positionToRemove;

    // Remove by plate
    deleteByPlate(head, plateToRemove);
    
    // Remove by position
    deleteByPosition(head, positionToRemove);

    // Print the final list
    printList(head);

    return 0;
}
