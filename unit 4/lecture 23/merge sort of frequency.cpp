#include <iostream>
using namespace std;

void merge(int arr[][2], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int L[n1][2], R[n2][2];

    for (int i = 0; i < n1; i++) {
        L[i][0] = arr[left + i][0];
        L[i][1] = arr[left + i][1];
    }
    for (int j = 0; j < n2; j++) {
        R[j][0] = arr[mid + 1 + j][0];
        R[j][1] = arr[mid + 1 + j][1];
    }

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i][1] < R[j][1] || (L[i][1] == R[j][1] && L[i][0] < R[j][0])) {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
        } else {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }
}

void mergeSort(int arr[][2], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cin >> n;
    int nums[n], freq[101] = {0}, freqArr[101][2], size = 0;

    // Read numbers and count frequencies
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        freq[nums[i]]++;
    }

    // Prepare the list of pairs (value, frequency)
    for (int i = 1; i <= 100; i++) {
        if (freq[i] > 0) {
            freqArr[size][0] = i;
            freqArr[size][1] = freq[i];
            size++;
        }
    }

    // Sort the list of pairs using merge sort
    mergeSort(freqArr, 0, size - 1);

    // Reconstruct the sorted numbers based on frequency
    int sortedNums[n], idx = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < freqArr[i][1]; j++) {
            sortedNums[idx++] = freqArr[i][0];
        }
    }

    // Print the sorted numbers
    for (int i = 0; i < n; i++) {
        cout << sortedNums[i] << " ";
    }
    cout << endl;

    return 0;
}
