// You are using GCC
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

void insertatpos(node* &head,string key,int pos){
    node* n=new node(key);
    if(pos==1){
        n->next=head;
        head=n;
        return;
    }
    node* temp=head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
        
    }
    if(temp==NULL){
        return;
        
    }
    n->next=temp->next;
    temp->next=n;
    
    
    
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
    cout<<endl;
    
}
int main(){
    node* head=NULL;
    
    int n;
    cin>>n;
    
    string data;
    for(int i=0;i<n;i++){
        cin>>data;
        insertattail(head,data);
    }
    int m;
    string key;
    cin>>key>>m;
    insertatpos(head,key,m);
    display(head);
    
}