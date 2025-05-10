#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void bellman(vector<vector<int>>&edges,int v,int e,int src){
    vector<int>distance(v,INT_MAX);
    distance[src] = 0;
    for(int i=0;i < v-1;i++)
    {
        int flag = 0;
        for(auto j : edges)
        {
            int u = j[0];
            int V = j[1];
            int wt = j[2];
            if(distance[u] + wt < distance[V]){
                flag = 1;
            }

        }
        if(flag == 0){
            for(auto j : edges){
                int u = j[0];
                int V = j[1];
                int wt = j[2];
                cout<<"";

            }
        }


    }


}
void bfs(){
    
}
int main(){
    int src,v,e;
    cout<<"enter vertices and edges :";
    cin>>v>>e;
    cout<<"enter source : ";
    cin>>src;
    vector<vector<int>>edges(e,vector<int>(3));
    cout<<"enter the list : ";
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[i] = {a,b,c};
    }
    bellman(edges,v,e,src);
    return 0;
}