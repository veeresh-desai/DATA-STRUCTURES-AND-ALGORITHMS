#include <iostream>
#include <string>
using namespace std;

int partition(string names[], int heights[], int low, int high) {
    int pivot = heights[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (heights[j] >= pivot) {
            i++;
            swap(heights[i], heights[j]);
            swap(names[i], names[j]);
        }
    }
    swap(heights[i + 1], heights[high]);
    swap(names[i + 1], names[high]);
    return i + 1;
}

void quickSort(string names[], int heights[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(names, heights, low, high);
        quickSort(names, heights, low, pivotIndex - 1);
        quickSort(names, heights, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    string *names = new string[n];
    int *heights = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> heights[i];
    }
    quickSort(names, heights, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << names[i] << " ";
    }
    cout << endl;
    delete[] names;
    delete[] heights;
    return 0;
}