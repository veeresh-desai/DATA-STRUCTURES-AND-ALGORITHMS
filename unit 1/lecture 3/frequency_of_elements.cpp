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
    bool counted[n]={false};
    for(int i=0;i<n;i++){
        
        if(counted[i]){
            continue;
        }
        int count=0;
        
        for(int j=0;j<n;j++){
            
            if(arr[i]==arr[j]){
                count++;
                counted[j]=true;
            }
        }
        cout<<arr[i]<<": "<<count<<endl;
        
    }
}