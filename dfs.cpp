#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 100
int stk[100];
int top = -1;
void push(int k){
    top++;
    stk[top] = k;
}
int pop(){
    if (top == -1) return -1;
    int v = stk[top];
    top--;
    return v;
}
bool dfs(int v,int graph[MAX_SIZE][MAX_SIZE],int src,int des){
    vector<int>visited(v,0);
    push(src);
    visited[src] = 1;
    while(top!=-1){
        int popped_value = pop();
        if(popped_value == des){
            return true;
        }
        for(int i = 0;i<v;i++){
            if(graph[popped_value][i]==1 && visited[i] == 0){
                push(i);
                visited[i] = 1;
            }
        }
    }
return false;
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

    cout << "Enter source and destination vertices: ";
    cin >> src >> des;

    if (dfs(v, graph, src, des)) {
        cout << "Path exists from " << src << " to " << des << endl;
    } else {
        cout << "No path exists from " << src << " to " << des << endl;
    }
    return 0;
}