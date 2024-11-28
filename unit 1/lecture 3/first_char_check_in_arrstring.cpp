// You are using GCC
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    string arr[100];
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,arr[i]);
    }
    char ch;
    cin>>ch;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i][0]==ch){
            count++;
        }
    
    }
    cout<<count;
    
}