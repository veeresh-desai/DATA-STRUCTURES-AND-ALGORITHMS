// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int recipeCode;
    Node* prev;
    Node* next;
    
    Node(int code) : recipeCode(code), prev(nullptr), next(nullptr) {}
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->recipeCode << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtEnd(Node*  &head, Node* &tail, int newRecipeCode) {
    
    Node* n=new Node(newRecipeCode);
    
    if(head==NULL){
        head=tail=n;
        return;
    }
    else{
        tail->next=n;
        n->prev=tail;
        tail=n;
        
        
    }
    
    
}

void removeByCode(Node* &head, Node* &tail, int recipeToRemove) {
    Node* temp=head;
    while(temp!=NULL && temp->recipeCode!=recipeToRemove){
        temp=temp->next;
        
    }
    
    if(temp==NULL){
        return;
    }
    
    if(temp->prev!=nullptr){
        temp->prev->next=temp->next;
    }else{
        head=temp->next;
    }
    
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }else{
        tail=temp->prev;
    }
    
    
 
    
}

int main() {
    int N;
    cin >> N;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < N; i++) {
        int recipeCode;
        cin >> recipeCode;
        insertAtEnd(head, tail, recipeCode);
    }

    int newRecipeCode, recipeToRemove;
    cin >> newRecipeCode;
    cin >> recipeToRemove;

    insertAtEnd(head, tail, newRecipeCode);
    printList(head);

    removeByCode(head, tail, recipeToRemove);
    printList(head);

    return 0;
}