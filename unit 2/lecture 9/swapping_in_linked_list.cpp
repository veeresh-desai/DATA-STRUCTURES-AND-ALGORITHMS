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

void insertattail(node* &head,int val){
    node* n=new node(val);
    
    if(head==nullptr){
        head=n;
        return;
    }
    
    node* temp=head;
    
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    
    n->next=temp->next;
    temp->next=n;
    
    return;
}

void swapping(node* &head){
    node* temp=head;
    
    while(temp!=NULL && temp->next!=NULL){
        swap(temp->data,temp->next->data);
        temp=temp->next->next;
    }
    
}

void display(node* head){
    node* temp=head;
    
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    int n;
    cin>>n;
    node* head=NULL;
    
    int data;
    for(int i=0;i<n;i++){
        cin>>data;
        insertattail(head,data);
    }
    cout<<"Before swapping: ";
    display(head);
    swapping(head);
    cout<<endl<<"After swapping: ";
    display(head);
    
}