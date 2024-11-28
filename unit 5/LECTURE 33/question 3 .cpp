#include <iostream>
using namespace std;

// You are using GCC
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to maintain the min-heap property
void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

// Function to build a min-heap from an array
void buildMinHeap(int heap[], int size) {
    for (int i = (size / 2) - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

// Function to insert an element into the heap
void insertElement(int heap[], int &size, int value) {
    heap[size] = value;
    size++;
    
    // Fix the min-heap property if it's violated
    int i = size - 1;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete elements within a specified range
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

// Function to display the min-heap
void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int heap[100];  // Array to store heap elements, fixed size
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value);
    }

    buildMinHeap(heap, size);

    cout << "Min-heap: ";
    displayMinHeap(heap, size);

    int low, high;
    cin >> low >> high;

    deleteInRange(heap, size, low, high);

    cout << "Min-heap after deletion: ";
    displayMinHeap(heap, size);

    return 0;
}