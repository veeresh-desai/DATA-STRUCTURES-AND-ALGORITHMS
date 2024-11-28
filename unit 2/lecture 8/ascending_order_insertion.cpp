// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int new_data){
        data=new_data;
        next=NULL;
    }
};

void sortedInsert(Node** head_ref, int new_data){
    Node* n=new Node(new_data);
    
    if(*head_ref==NULL|| (*head_ref)->data >=new_data){
        n->next=*head_ref;
        *head_ref=n;
        return;
    }
    
    Node *temp=*head_ref;
    
    while(temp->next!=NULL && temp->next->data<new_data){
        temp=temp->next;
        
    }
    
    n->next=temp->next;
    temp->next=n;
    
    
}

void printList(Node* head)
{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
    
    //Type your code here
    
}

int main()
{
    Node* head = NULL;
    int n, data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        sortedInsert(&head, data);
    }

    cin >> data;
    sortedInsert(&head, data);

    printList(head);

    return 0;
}