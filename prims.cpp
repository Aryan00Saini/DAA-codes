#include<iostream>
#include<vector>
#include<utility>
#include<climits>
using namespace std; 
int min_key(vector<int>&dist,vector<bool>&mst){
    int min = INT_MAX;
    int idx = -1;
    for(int k=0;k<dist.size();k++){
        if( !mst[k] && dist[k] < min){
            min = dist[k];
            idx = k;
        }
    }
    return idx;
}
void prims(vector<vector<pair<int,int>>>&adjlist,int v,int e,int src){
    vector<int>parent(v,-1);
    vector<bool>mst(v,false);
    vector<int>dist(v,INT_MAX);
    dist[src] = 0;
    int sum = 0;
    for(int i=0;i<v-1;i++){
        int edge = min_key(dist,mst);
        mst[edge] = true;
        for(auto j : adjlist[edge]){
            int first = j.first;
            int second = j.second;
            if( !mst[first] && second < dist[first]){
                dist[first] = second;
                parent[first] = edge;
            }
        }
    }
    for(int i=0;i<v;i++){
        sum += dist[i];
    }
    cout<<"MST : "<<sum;

}
int main(){
    int e,v,src;
    cout<<"enter v and e :";
    cin>>v>>e;
    cout<<"enter source : ";
    cin>>src;
    vector<vector<pair<int,int>>>adjlist(v);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }
    prims(adjlist,v,e,src);

    return 0;
}