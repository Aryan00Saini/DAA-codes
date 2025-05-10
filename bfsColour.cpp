#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 100
int q[100];
int front = -1,rear = -1;
void enqueue(int k){
    front++;
    q[front] = k;
}
int dequeue(){
    if (rear == 100) return -1;
    rear++;
    int v = q[rear];
    return v;
}
bool bfs(int v,int graph[MAX_SIZE][MAX_SIZE],int src,int des){
    vector<int>color(v,-1);
    enqueue(0);
    color[0] = 0;
    while(rear < 100){
        int u = dequeue();
        for(int i = 0;i<v;i++){
            if(graph[u][i]==1){
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                }
                else if(color[v] == color[u]){
                    return false;
                }
                else continue;
            }
        }
    }
return true;
}
int main() { 
    int v,src,des;
    cout << "enter the no. of vertices";
    cin >> v;
    int graph[MAX_SIZE][MAX_SIZE];
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source : ";
    cin >> src;

    if (bfs(v, graph, src, des)) {
        cout << "yes "<< endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}