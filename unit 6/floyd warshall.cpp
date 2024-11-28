#include <iostream>
using namespace std;

#define INF 10000000
#define MAXN 100

int dis[MAXN][MAXN];
int Next[MAXN][MAXN];

void initialise(int V, int graph[MAXN][MAXN]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == 0 && i != j) {
                dis[i][j] = INF;
            } else {
                dis[i][j] = graph[i][j];
            }
            if (graph[i][j] != 0 && i != j) {
                Next[i][j] = j;
            } else {
                Next[i][j] = -1;
            }
        }
    }
}

void floydWarshall(int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    Next[i][j] = Next[i][k];
                }
            }
        }
    }
}

void printPath(int path[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " -> ";
        cout << path[i];
    }
    cout << endl;
}

int main() {
    int V;
    cin >> V;

    int graph[MAXN][MAXN];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    initialise(V, graph);
    floydWarshall(V);

    int u = 0; // Top-left corner
    int v = V - 1; // Bottom-right corner

    if (Next[u][v] == -1) {
        cout << "No path exists from " << u << " to " << v << endl;
        return 0;
    }

    int path[MAXN];
    path[0] = u;
    int index = 1;
    while (u != v) {
        u = Next[u][v];
        path[index++] = u;
    }

    printPath(path, index);

    return 0;
}
