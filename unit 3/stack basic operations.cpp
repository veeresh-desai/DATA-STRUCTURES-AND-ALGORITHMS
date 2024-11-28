#include<iostream>
using namespace std;

class Stack{
    private:
    int top;
    int arr[10];
    public:
    Stack(){
        top=-1;
        
    }
    bool isfull(){
        return top==9;
    }
    bool isempty(){
        return top==-1;
    }
    void push(int item){
        if(isfull()){
            cout<<"stack overflow";
            
        }
        
        else{
            arr[++top]=item;
            cout<<item<<" pushed"<<endl;
        }
    }
    
    void pop(){
        if(isempty()){
            cout<<"stack underflow";
        }else{
            
            cout<<arr[top--]<<" popped";
            cout<<endl;
            
        }
        
    }
    
    void display(){
        if(isempty()){
            cout<<"underflow";
        }
        else{
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    
    void peek(){
        if(isempty()){
            cout<<"stack underflow";
        }else{
            cout<<arr[top];
            cout<<endl;
        }
    }
       
};


int main(){
    Stack stack;
    
    int n;
    cin>>n;
    int item;
    
    for(int i=0;i<n;i++){
        cin>>item;
        stack.push(item);
    }

    stack.display();
    stack.peek();
    stack.pop();
    stack.display();
    
    
}
