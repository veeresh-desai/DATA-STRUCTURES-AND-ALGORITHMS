// You are using GCC
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Original array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int loc,element;
    cin>>loc>>element;
    if(loc>n+1){
        cout<<"Invalid position!";
        
    }else{
        
    
    for(int i=n;i>=loc;i--){
        arr[i]=arr[i-1];
    }
    arr[loc-1]=element;
    n++;
    cout<<"Updated array: "; 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    }
    
    
}