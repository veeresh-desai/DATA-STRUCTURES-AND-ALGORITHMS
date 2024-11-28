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

void insertathead(node* &head,int val){
    node* n=new node(val);
    
    n->next=head;
    head=n;
    return;
    
}

void display(node* head){
    node* temp=head;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
}
int main(){
    int n;
    cin>>n;
    node* head=NULL;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        
        insertathead(head,data);
    }
    cout<<"Created Linked list: ";
    display(head);
    cout<<endl;
    int data;
    cin>>data;
    insertathead(head,data);
    cout<<"Final list: ";
    display(head);
    
}