#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To handle newline after integer input

    if (n == 0) {
        cout << "Message queue is empty!" << endl;
        return 0;
    }

    vector<string> messages(n);
    
    // Input messages
    for (int i = 0; i < n; ++i) {
        getline(cin, messages[i]);
    }

    // Output messages in reverse order
    cout << "Message Queue:" << endl;
    for (int i = n - 1; i >= 0; --i) {
        cout << "- " << messages[i] << endl;
    }

    return 0;
}
