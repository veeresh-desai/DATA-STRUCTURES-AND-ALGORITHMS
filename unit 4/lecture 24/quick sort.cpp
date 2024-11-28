#include <iostream>
#include <string>
using namespace std;

int partition(string arr[], int low, int high) {
    string pivot = arr[high];
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

void quickSort(string arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    string *words = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    quickSort(words, 0, n - 1);
    for (int i = n-1; i >=0 ; i--) {
        cout << words[i] << " ";
    }
    cout << endl;
    delete[] words;
    return 0;
}    