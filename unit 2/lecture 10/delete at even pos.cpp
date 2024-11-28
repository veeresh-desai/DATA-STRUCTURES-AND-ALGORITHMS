// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteEvenPositionNodes(Node*& head,int pos) {
    if (head == NULL) {
        return;
    }

    if (pos == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos-1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return;
    }

    Node* nodetodel = temp->next;
    temp->next = temp->next->next;
    delete nodetodel;
    
}
void displayLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int size;

    cin >> size;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        insertNode(&head, value);
    }

    cout << "Original Linked List: ";
    displayLinkedList(head);
    for(int i=size;i>=0;i--){
        
        if(i%2!=0){
        deleteEvenPositionNodes(head,i);
        }
    }

    cout << "Final Linked List: ";
    displayLinkedList(head);

    Node* temp = head;
    while (head != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }

    return 0;
}