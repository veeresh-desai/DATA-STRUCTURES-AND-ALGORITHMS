#include <iostream>
#include <cmath> 
using namespace std;



void heapify(int arr[], int n, int i) {
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

void heapSort(int arr[], int size) {
    //Type your code here
    for(int i=size/2-1;i>=0;i--){
        heapify(arr,size,i);
    }
    for(int i=size-1;i>0;i--){
        swap(arr[0],arr[i]);
        
        heapify(arr,i,0);
    }
}

void extractDigits(int num, int*& digits, int& digitCount) {
    //Type your code here
    int temp=num;
    digitCount=0;
    while(temp>0){
        temp/=10;
        (digitCount)++;
        
    }
    
    digits=new int [digitCount];
    
    int index=digitCount-1;
    while(num>0){
        digits[index--]=num%10;
        num/=10;
    }
}

void printSortedDigits(int digits[], int digitCount) {
    //Type your code here
    
    for(int i=digitCount-1;i>=0;i--){
        cout<<digits[i]<<" ";
    }
}

int main() {
    int num;
    cin >> num;
    int* digits = nullptr;
    int digitCount = 0;
    extractDigits(num, digits, digitCount);
    heapSort(digits, digitCount);
    printSortedDigits(digits, digitCount);
    delete[] digits; 
    return 0;
}