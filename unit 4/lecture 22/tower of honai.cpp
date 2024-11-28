#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int& moves) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, moves);
    cout << "Move disk " << n << " from " << from_rod << " to " << to_rod << endl;
    moves++;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, moves);
}

int main() {
    int n; // Number of disks
    cin>>n;
    int moves = 0;
    towerOfHanoi(n, 'A', 'C', 'B', moves);
    cout << "Total number of moves: " << moves << endl;
    return 0;
}
