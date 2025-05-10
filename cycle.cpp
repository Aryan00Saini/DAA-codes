#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasCycle(int v,vector<vector<int>>& adj) {
    vector<int> inDegree(v, 0);
    for (int u = 0; u < v; ++u) {
        for (int nbr : adj[u]) {
            inDegree[nbr]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;

        for (int nbr : adj[node]) {
            if (--inDegree[nbr] == 0)
                q.push(nbr);
        }
    }

    return (count != v); 
}

int main() {
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> adj(v); 
    cout << "Enter edges";
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);  
    }

    if (hasCycle(v, adj))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}


