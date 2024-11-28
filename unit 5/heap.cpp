

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


void buildMinHeap(int arr[], int n) {
    //Type your code here
    for(int i=n/2-1;i>=0;i--){
        minHeapify(arr,n,i);
    }
}
void buildMaxHeap(int arr[], int n)
{
    //Type your code here
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
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
void deleteRoot(int arr[], int &n)
{
    //Type your code here
    arr[0]=arr[n-1];
    n--;
    heapify(arr,n,0);
    
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
void deleteInRange(int heap[], int &size, int low, int high) {
    for (int i = 0; i < size;) {
        if (heap[i] >= low && heap[i] <= high) {
            swap(&heap[i], &heap[size - 1]);
            size--;  // Reduce heap size
            minHeapify(heap, size, i);  // Fix heap property
        } else {
            i++;
        }
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
int sumOfLeafNodes(int arr[], int n) {
    //Type your code here
    int sum=0;
    for(int i=n/2;i<n;i++){
        sum+=arr[i];
    }
    
    return sum;
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

void printHeapArray(int arr[], int n)
{
    //Type your code here
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}




void insertelement(int arr[],int &n,int value){
    n++;

    int index=n;
    arr[index]=value;


    

    while(index>0){
        int parent=(index-1)/2;
        if(arr[index]>arr[parent]){
            swap(arr[index],arr[parent]);
            index=parent;
        }
        else{
            return ;
        }

    }


}