#include <iostream>
#include <iomanip> 

using namespace std;



void minHeapify(int arr[], int n, int i) {
    //Type your code here
    int smallest=i;
    int left=2*i +1;
    int right=2*i+2;
    if(left<n && arr[left]<arr[smallest]){
        smallest=left;
        
    }
    
    if(right<n && arr[right]<arr[smallest]){
        smallest=right;
    }
    
    if(smallest!=i){
        int temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
        minHeapify(arr,n,smallest);
    }
    
}

void buildMinHeap(int arr[], int n) {
    //Type your code here
    for(int i=n/2-1;i>0;i--){
        minHeapify(arr,n,i);
    }
}

int filterElements(int arr[], int *n, double avg) {
    //Type your code here
    for(int i=0;i<=*n;i++){
        
        int index=-1;
        for(int j=0;i<=*n;i++){
            if(arr[i]<avg){
                index=i;
                break;
            }
            
        }
        if(index==-1){
            return *n;
            
        }
        
        arr[index]=arr[*n-1];
        (*n)--;
    }
    
    return *n;
    
}

double calculateAverage(int arr[], int n) {
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

    int* arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMinHeap(arr, n);

    double avg = calculateAverage(arr, n);

    n = filterElements(arr, &n, avg);

    cout << "Average: " << fixed << setprecision(2) << avg << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}