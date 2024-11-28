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

void insertathead(node* &head,int key){
    node* n=new node(key);
    n->next=head;
    head=n;
    return;
}

void display(node* head){
    node* temp=head;
    cout<<"Linked List: ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
}
int main(){
    int data;
    int choice;
    node* head=NULL;
    do{
        cin>>data;
        insertathead(head,data);
        cout<<"Node inserted"<<endl;
        cin>>choice;
        
        
    }while(choice==0);
    
    display(head);
    cout<<endl<<"Node ended";
    
}