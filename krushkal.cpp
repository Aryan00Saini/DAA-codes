#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
int findparent(int u, vector<int>& parent) {
    if (parent[u] != u) {
        parent[u] = findparent(parent[u], parent);
    }
    return parent[u];
}

void changeparent(int u, int v, vector<int>& parent) {
    int pu = findparent(u, parent);
    int pv = findparent(v, parent);
    if (pu != pv) {
        parent[pu] = pv;
    }
}

int main() {
    int e, v, src;
    cout << "Enter v and e: ";
    cin >> v >> e;
    
    vector<vector<int>> edges(e, vector<int>(3));
    cout << "Enter edges:" << endl;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b}; 
    }
    sort(edges.begin(), edges.end());
    
    vector<int> parent(v);
    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }
    
    int sum = 0;
    int countedge = 0;
    for (int i = 0; i < e && countedge < v-1; i++) {
        int wt = edges[i][0];
        int u = edges[i][1];
        int s = edges[i][2];
        
        if (findparent(u, parent) != findparent(s, parent)) {
            sum += wt;
            countedge++;
            changeparent(u, s, parent);
        }
    }
    
    cout << "Total weight of MST: " << sum << endl;
    
    return 0;
}
