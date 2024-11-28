// You are using GCC
#include<iostream>

using namespace std;


class heap{
    public:
    int arr[20];
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
            
            if(arr[parent]>arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
                
            }
            else{
                return ;
                
            }
        }
        
    }
    
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
            
        }
        cout<<endl;
    }
    
    void find(int item){
        
        bool found=false;
        for(int i=1;i<=size;i++){
            if(arr[i]==item){
                cout<<item<<"is present";
                found=true;
                return;
                
            }
        }
        if(found==false){
            cout<<item<<"is not present";
        }    
    }
    
};

int main(){
    int n;
    cin>>n;
    
    heap h;
    
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        
        h.insert(val);
    }
    
    int item;
    cin>>item;
    
    h.print();
    h.find(item);
    
}