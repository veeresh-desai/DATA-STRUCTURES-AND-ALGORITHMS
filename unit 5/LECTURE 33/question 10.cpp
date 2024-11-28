#include <iostream>
using namespace std;

// You are using GCC
void MaxHeapify(int arr[], int N, int i)
{
    //Type your code here
    
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<N && arr[left]>arr[largest]){
        largest=left;
    }
    
    if(right<N && arr[right]>arr[largest]){
        largest=right;
    }
    
    if(largest!=i){
        swap(arr[i],arr[largest]);
        MaxHeapify(arr,N,largest);
    }
    
    
    
    
}
void MaxHeapSort(int arr[], int N)
{
    //Type your code here
    for(int i=N/2-1;i>=0;i--){
        MaxHeapify(arr,N,i);
    }
    
    for(int size=N-1;size>0;size--){
        swap(arr[0],arr[size]);
        MaxHeapify(arr,size,0);
    }
    
    
}
void MinHeapify(int arr[], int N, int i)
{
    
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<N && arr[left]<arr[smallest]){
        smallest=left;
    }
    
    if(right<N && arr[right]<arr[smallest]){
        smallest=right;
    }
    
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        MinHeapify(arr,N,smallest);
    }
    
}

void MinHeapSort(int arr[], int N)
{
    //Type your code here
    for(int i=N/2-1;i>=0;i--){
        MinHeapify(arr,N,i);
    }
    
    for(int size=N-1;size>0;size--){
        swap(arr[0],arr[size]);
        MinHeapify(arr,size,0);
    }
}

void printHeapArray(int arr[], int n)
{
    //Type your code here
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 2) {
        cout << "Invalid choice";
        return 0;
    }
    if (choice == 1) {
        MaxHeapSort(arr, n);
    }
    else if (choice == 2) {
        MinHeapSort(arr, n);
    }
    printHeapArray(arr, n);
    return 0;
}