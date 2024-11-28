// You are using GCC
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string arr[100];
    
    cin.ignore();
    for(int i=0;i<n+1;i++){
        getline(cin,arr[i]);
    }
    int count=0;
    string target=arr[n];
    bool found=false;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<i;
            found=true;
            
        }
    }
    if(found==false){
        cout<<"String not found!";
    }
    
}