#include <iostream>
using namespace std;


void heapify(int arr[], int n, int i) {
    //Type your code here
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    
    if(left<n && arr[left]>arr[smallest]){
        smallest=left;
    }
    
    if(right<n && arr[right]>arr[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
}

void heapSort(int arr[], int size) {
  
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
    int arr[size];
    int odd[size], even[size];
    int oddCount = 0, evenCount = 0;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        if (arr[i] % 2 != 0) {
            odd[oddCount++] = arr[i];
        } else {
            even[evenCount++] = arr[i];
        }
    }
    heapSort(odd, oddCount);
    heapSort(even, evenCount);

    for (int i = 0; i < oddCount; i++) {
        cout << odd[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < evenCount; i++) {
        cout << even[i] << " ";
    }

    return 0;
}