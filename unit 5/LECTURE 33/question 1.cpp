#include <iostream>
using namespace std;

#define MAX_SIZE 100

// You are using GCC
void heapify(int arr[], int n, int i)
{
    //Type your code here
    int largest=i;
    int left=2 * i +1;
    int right=2 * i +2;
    
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
    
    
}

void buildMaxHeap(int arr[], int n)
{
    //Type your code here
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}

void deleteRoot(int arr[], int &n)
{
    //Type your code here
    arr[0]=arr[n-1];
    n--;
    heapify(arr,n,0);
}

void printArray(int arr[], int n)
{
    //Type your code here
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}


int main()
{
    int n;
    cin >> n;

    int arr[MAX_SIZE];

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    buildMaxHeap(arr, n);
    deleteRoot(arr, n);
    printArray(arr, n);

    return 0;
}