#include<iostream>
using namespace std;

struct node{
    string data;
    node* next;
    
    node(string val){
        data=val;
        next=NULL;
        
    }
};
void insertathead(node* &head,string val){
    node* n=new node(val);
    n->next=head;
    head=n;
    
    
}
void insertattail(node* &head,string val){
    node* n=new node(val);
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

void display(node* head){
    node* temp=head;
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
    cout<<endl;
    
}


int main(){
    int n;
    cin>>n;
    string data;
    
    node* head=NULL;
    for(int i=0;i<n;i++){
        cin>>data;
        insertathead(head,data);
    }
    cout<<"Document: ";
    display(head);
    cin>>data;
    insertattail(head,data);
    cout<<"Updated Document: ";
    display(head);
    
    
}