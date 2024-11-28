// You are using GCC
#include <iostream>
using namespace std;

int moveDisks(int n, char source, char auxiliary, char destination) {
    //Type your code here
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return 1;
    }
    int moves = 0;
    moves += moveDisks(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    moves += 1;
    moves += moveDisks(n - 1, auxiliary, source, destination);
    return moves;

}

int main() {
    int n;
    cin >> n;
    
    int totalMoves = moveDisks(n, '1', '2', '3');
    
    cout << totalMoves << endl;
    
    return 0;
}