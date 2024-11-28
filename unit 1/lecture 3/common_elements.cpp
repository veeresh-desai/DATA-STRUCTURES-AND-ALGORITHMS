// You are using GCC
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    
    int m;
    cin>>m;
    int arr2[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    bool found=false;
    cout<<"Common Elements: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i]==arr2[j]){
                cout<<arr2[j]<<" ";
                found=true;
                break;
            }
        }
        
    }
    if(!found){
        cout<<"None";
    }
    
}