#include <iostream>
#include <string>
using namespace std;

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    char characters[n];
    for (int i = 0; i < n; ++i) {
        cin >> characters[i];
    }

    quickSort(characters, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        cout << characters[i] << " ";
    }
    cout << endl;
    return 0;
}