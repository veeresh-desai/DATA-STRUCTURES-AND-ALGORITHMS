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
    bool checked=false;
    for(int i=0;i<n;i++){
        int count=0;
        //bool checked=false;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
                
            }
        }
        if(count>n/2){
            cout<<"The majority candidate is ID"<<" "<<arr[i];
            checked=true;
            break;
        }
    }
    if(checked==false){
        cout<<"No majority candidate found";
    }
}