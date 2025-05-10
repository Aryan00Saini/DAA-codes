#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int shortestPathKEdges(int V, vector<vector<int>>& edges, int src, int dest, int K) {
    vector<vector<int>> dp(V, vector<int>(K + 1, INT_MAX));

    dp[src][0] = 0; 
    for (int k = 1; k <= K; k++) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dp[u][k - 1] != INT_MAX) {
                dp[v][k] = min(dp[v][k], dp[u][k - 1] + wt);
            }
        }
    }
    if(dp[dest][K] == INT_MAX){
        return -1;
    }
    return dp[dest][K];
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter edges (from to weight):";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src, dest, K;
    cout << "Enter source, destination and exact number of edges (K): ";
    cin >> src >> dest >> K;

    int result = shortestPathKEdges(V, edges, src, dest, K);
    if (result == -1) {
        cout << "No path exists with exactly " << K << " edges." << endl;
    } else {
        cout << "Shortest path from " << src << " to " << dest << " with exactly " << K << " edges is: " << result << endl;
    }

    return 0;
}
