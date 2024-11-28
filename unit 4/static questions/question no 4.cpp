#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = n2 - 1; i >= 0; i--)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int size) {
    static int rec = 0; // Declare rec here as static

    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);

        merge(arr, l, m, r);

        // Print the array after each merge step
        cout << "After iteration " << ++rec <<endl;
        printArray(arr, size);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Given Array" << endl;
    printArray(arr, n);

    mergeSort(arr, 0, n - 1, n);

    cout << "Sorted Array" << endl;
    printArray(arr, n);

    return 0;
}