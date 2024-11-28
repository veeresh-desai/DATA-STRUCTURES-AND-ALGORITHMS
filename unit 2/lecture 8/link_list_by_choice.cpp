// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    
    Node(int val1){
        val=val1;
        next=NULL;
        
    }
    
};

void appendLeft(Node* &head, int val) {
    //Type your code here
    Node* n=new Node(val);
    n->next=head;
    head=n;
    return;
    
}

void appendRight(Node* &head, int val) {
    //Type your code here
    Node* n=new Node(val);
    if(head==NULL){
        head=n;
        return;
    }
    Node* temp=head;
    
    while(temp->next!=nullptr){
        temp=temp->next;
        
    }
    temp->next=n;
    
    
    
}

void print(Node* head) {
    //Type your code here
    Node* temp=head;
    
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    
}

int main() {
    Node* myList = nullptr;
    int choice;
    int val;

    do {
    cin >> choice;


    switch (choice) {
        case 1:
            cin >> val;
            appendLeft(myList, val);
            break;
        case 2:
            cin >> val;
            appendRight(myList, val);
            break;
        case 3:
            cout << "Linked List: ";
            print(myList);
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" ;
    }

} while (choice != 4);


    return 0;
}