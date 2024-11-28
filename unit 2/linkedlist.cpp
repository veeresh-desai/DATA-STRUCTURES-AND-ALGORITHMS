// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    
    
    node(int val){
        data=val;
        next=NULL;
        
    }
};
void insertattail(node* &head,int val){
    node *n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    
    while(temp->next!=NULL){
        temp=temp->next;
        
    }
    temp->next=n;
    
    
}

void insertathead(node* &head,int val){
    node *n=new node(val);
    n->next=head;
    head=n;
    
    
}

void display(node* head){
    node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
        
    }
    cout<<"NULL"<<endl;
    
}

bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
            
        }
        temp=temp->next;
    }
    return false;
    
}
int main() {
    node *head=NULL;
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    display(head);
    insertathead(head,6);
    display(head);
    cout<<search(head,0)<<endl;
    
}