#include <iostream>
using namespace std;


void maxHeapify(int arr[], int n, int i) {
    //Type your code here
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
    
    
}
void buildMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=n/2-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
    
}
void insertIntoMaxHeap(int arr[], int &size, int value, int &evenCount, int &oddCount)
{
    //Type your code here
    size++;
        
        int index=size-1;
        
        arr[index]=value;
        if(value%2==0){
            evenCount++;
        }else{
            oddCount++;
        }
        
        while(index>0){
            int parent=(index-1)/2;
            
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
                
            }
            else{
                return;
                
            }
        }
        
        
}
void printMaxHeap(int arr[], int n) {
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    //Type your code here
}


int main() {
    int arr[100];
    int n = 0;
    int num_elements;
    int evenCount = 0, oddCount = 0; 
    cin >> num_elements;
    for (int i = 0; i < num_elements; i++) {
        int value;
        cin >> value;
        insertIntoMaxHeap(arr, n, value, evenCount, oddCount);
    }
    buildMaxHeap(arr, n);
    cout << "Max Heap: ";
    printMaxHeap(arr, n);
    cout << "Even elements count: " << evenCount << endl;
    cout << "Odd elements count: " << oddCount;
    return 0;
}