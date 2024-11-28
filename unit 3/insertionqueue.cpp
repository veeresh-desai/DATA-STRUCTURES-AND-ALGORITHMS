#include<iostream>
using namespace std;

int q[10];
int front=0;
int rear=0;
int n=5;

void insert(int val){
    if((front==1 && rear==n)||(front==rear+1)){
        cout<<"overflow";
        return;
    }
    if(front==0){
        front=1;
        rear=1;

    }

    else{
        if(rear==n){
            rear=1;
        }else{
            rear=rear+1;
        }
    }
    q[rear]=val;

}
void delete(){
    if(front==0){
        cout<<"underflow";
        return;
    }
    
    cout<<q[front];
    if(front==rear){
        front=0;
        rear=0;

    }
    else{
        if(front==n){
            front=1;

        }else{
            front=front+1;
        }
    }


}
void display(){

}
int main(){

}