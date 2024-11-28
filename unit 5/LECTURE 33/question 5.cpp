#include <iostream>
using namespace std;


void maxHeapify(int arr[], int N, int i) {
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
        maxHeapify(arr,N,largest);
    }
    
    
}

void buildMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=n/2-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
}
    


void insertIntoMaxHeap(int arr[], int *n, int value) {
    //Type your code here
    arr[*n]=value;
    int i=*n;
    (*n)++;
    
    while(i!=0 && arr[(i-1)/2]<arr[i]){
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
    
    
}

void deleteRoot(int arr[], int *n) {
    //Type your code here
    arr[0]=arr[*n-1];
    (*n)--;
    maxHeapify(arr,*n,0);
    
}

int sumOfLeafNodes(int arr[], int n) {
    //Type your code here
    int sum=0;
    for(int i=n/2;i<n;i++){
        sum+=arr[i];
    }
    
    return sum;
}

void printMaxHeap(int arr[], int n) {
    //Type your code here
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    
}


int main() {
    int arr[100];
    int n = 0;
    int num_elements;

    cin >> num_elements;

    for (int i = 0; i < num_elements; i++) {
        int value;
        cin >> value;
        insertIntoMaxHeap(arr, &n, value);
    }

    buildMaxHeap(arr, n);

    printMaxHeap(arr, n);

    deleteRoot(arr, &n);

    printMaxHeap(arr, n);

    int leafSum = sumOfLeafNodes(arr, n);
    cout << "Sum of leaf nodes: " << leafSum;

    return 0;
}