#include <iostream>
using namespace std;


    
void heapify(char arr[], int n, int i) {
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

void heapSort(char arr[], int size) {
    //Type your code here
    for(int i=size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }
    for(int i=size-1;i>0;i--){
        swap(arr[0],arr[i]);
        
        heapify(arr,i,0);
    }
}


int main() {
    int size;
    cin >> size;
    char arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    heapSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}