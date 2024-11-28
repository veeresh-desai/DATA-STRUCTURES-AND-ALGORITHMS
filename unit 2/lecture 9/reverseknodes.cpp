// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    // Node(int val){
    //     data=val;
    //     next=NULL;
    // }
};

Node* createNode(int data) {
    Node* newNode = new Node(); 
    newNode->data = data;   
    newNode->next = nullptr;    
    return newNode;  
    
    
    
}

Node* reverseKNodes(Node* head, int k) {
    //if (!head) return nullptr;

    Node* temp= head;
    Node* next = nullptr;
    Node* prev = nullptr;
    int count = 0;

    while (temp != nullptr && count < k) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
        count++;
    }

    if (next != nullptr) {
        head->next = reverseKNodes(next, k);
    }

    return prev;
    
}

void displayList(Node* head) {
    Node* temp=head;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
    
}

void deleteList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int n, k;
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cin >> k;

    cout << "Original Linked List: ";
    displayList(head);
    cout<<endl;

    head = reverseKNodes(head, k);

    cout << "Modified Linked List: ";
    displayList(head);

    deleteList(head);

    return 0;
}