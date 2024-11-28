#include <iostream>
using namespace std;


void minHeapify(int arr[], int n, int i) {
    //Type your code here
    int smallest=i;
    int left=2 *i +1;
    int right= 2* i+2;
    
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

void deleteElement(int arr[], int& n, int key) {
    //Type your code here
    
    int index=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            index=i;
            break;
        }
    }
    if(index==-1){
        return;
    }
    
    arr[index]=arr[n-1];
    n--;
    buildMinHeap(arr,n);
    
    
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    buildMinHeap(arr, n);

    deleteElement(arr, n, key);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}