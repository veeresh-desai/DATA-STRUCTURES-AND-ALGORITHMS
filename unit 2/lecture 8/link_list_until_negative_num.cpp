// You are using GCC
#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    
    node(int val){
        data=val;
        next=NULL;
        
    }
};

void insertattail(node* &head,int key){
    node* n=new node(key);
    
    if(head==NULL){
        head=n;
        return;
        
    }
    node *temp=head;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    
    temp->next=n;
    
}

void display(node* head){
    if(head->next==NULL){
        cout<<"Linked List is empty.";
        return;
    }
    node* temp=head;
    
    cout<<"Linked List: ";
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    int data;
    
    node* head=NULL;
    do{
        cin>>data;
        insertattail(head,data);
        
    }while(data>0);
    
    display(head);
    
}