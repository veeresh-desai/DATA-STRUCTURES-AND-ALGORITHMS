#include <iostream>
#include <iomanip>

using namespace std;


void minHeapify(int arr[], int n, int i) {
    //Type your code here
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<n && arr[left]<arr[smallest]){
        smallest=left;
    }
    if(right<n && arr[right]<arr[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        minHeapify(arr,n,smallest);
    }
    
}

void buildMinHeap(int arr[], int n) {
    //Type your code here
    for(int i=n/2-1;i>=0;i--){
        minHeapify(arr,n,i);
    }
}

void insertElement(int arr[], int &size, int value) {
    //Type your code here
    size++;
        
        int index=size-1;
        
        arr[index]=value;
        
        while(index>0){
            int parent=(index-1)/2;
            
            if(arr[parent]>arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
                
            }
            else{
                return;
                
            }
        }
}

void displayMinHeap(int arr[], int n) {
    //Type your code here
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

double averageOfElements(int arr[], int n) {
    //Type your code here
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    
    return (double)sum/n;
}

int main() {
    int n;
    cin >> n;

    int *heap = new int[n]; // Dynamic memory allocation for heap
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value);
    }
    
    buildMinHeap(heap, size);
    displayMinHeap(heap, size);

    double average = averageOfElements(heap, size);
    cout << "Average: "<< fixed << setprecision(2)<< average;

    delete[] heap; // Free dynamically allocated memory
    return 0;
}