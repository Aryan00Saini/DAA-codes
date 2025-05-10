#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int v,e;
    cout<<"enter the vertices and edges : ";
    cin>>v>>e;
    int graph[v][v];
    for(int i =0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i!=j){
                graph[i][j] = INT_MAX;
            }
            else graph[i][j] = 0;
        }
    }
    cout << "enter edges : "<<endl;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    for(int k = 0; k < v ; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if(graph[i][j] != INT_MAX && graph[k][j] != INT_MAX)
                {
                    graph[i][j] = min(graph[i][j],graph[i][j]+graph[k][j]);
                }
                    
            }
                
        }     
    }

    cout<<"output :- "<<endl;
    for(int i =0;i<v;i++){
        for(int j=0;j<v;j++){
            if(graph[i][j] != INT_MAX){
                cout<<graph[i][j]<<" ";
            }
            else cout<<"INF"<<" ";
        }
        cout<<"\n";
    }
    return 0;
}