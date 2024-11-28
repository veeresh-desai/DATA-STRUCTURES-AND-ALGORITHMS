
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Patient {
public:
    string name;
    int severity;

    Patient(string n, int s) : name(n), severity(s) {}

    // Overload the < operator to create a max-heap based on severity
    bool operator<(const Patient& other) const {
        return severity < other.severity;
    }
};

int main() {
    priority_queue<Patient> pq;
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        string name;
        int severity;
        cin >> name >> severity;
        pq.push(Patient(name, severity));
    }

    while (!pq.empty()) {
        Patient p = pq.top();
        pq.pop();
        cout << "Treating patient: " << p.name << " (Severity: " << p.severity << ")" << endl;
    }

    return 0;
}