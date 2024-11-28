// You are using GCC
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int loc;
    char element;
    cin>>loc>>element;
    
    for(int i=n;i>=loc;i--){
        arr[i+1]=arr[i];
        
    }
    arr[loc]=element;
    n++;
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}