// You are using GCC
#include<iostream>
using namespace std;

class heap{
    public:
    int arr[15];
    int size;
    
    heap(){
        arr[0]=-1;
        
        size=0;
    }
    
    
    void insert(int val){
        size++;
        
        int index=size;
        
        arr[index]=val;
        
        while(index>1){
            int parent=index/2;
            
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
                
            }
        }
        
        
    }
    
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    
    void print_cube(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]*arr[i]*arr[i]<<" ";
        }
    }
    
};

int main(){
    int n;
    cin>>n;
    
    heap h;
    
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        
        h.insert(value);
    }
    
    h.print();
    h.print_cube();
    
}