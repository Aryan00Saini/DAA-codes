#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void bellman(vector<vector<int>>& edges, int v, int e, int src) {
    vector<int> distance(v, INT_MAX);
    distance[src] = 0;
    for (int i = 0; i < v - 1; i++) {
        for (auto edge : edges) {
            int u = edge[0];
            int vtx = edge[1];
            int wt = edge[2];
            if (distance[u] != INT_MAX && distance[u] + wt < distance[vtx]) {
                distance[vtx] = distance[u] + wt;
            }
        }
    }

    for (auto edge : edges) {
        int u = edge[0];
        int vtx = edge[1];
        int wt = edge[2];
        if (distance[u] != INT_MAX && distance[u] + wt < distance[vtx]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < v; i++) {
        if (distance[i] == INT_MAX) {
            cout << "Vertex " << i << " is unreachable." << endl;
        } else {
            cout << "Vertex " << i << ":" << distance[i] << endl;
        }
    }
}

int main() {
    int src, v, e;   
    cout << "Enter v and e: ";
    cin >> v >> e;
    cout << "Enter source: ";
    cin >> src;

    vector<vector<int>> edges(e, vector<int>(3));
    cout << "Enter edges " << endl;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    bellman(edges, v, e, src);
    return 0;
}
