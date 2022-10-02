#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,wt;
    edge(int x,int y,int z){
        u=x;
        v=y;
        wt=z;
    }
};

void belmenFord(vector<edge>Edges,int v,int e){
    vector<int>parent(v);
    vector<int>cost(v,INT_MAX);
    parent[0]=-1;
    cost[0]=0;
    bool updated;
    for(int i=0;i<v-1;i++){
        updated=false;
        for(int j=0;j<e;j++){
            int u=Edges[j].u;
            int v=Edges[j].v;
            int wt=Edges[j].wt;
            if(cost[u]+wt<cost[v]){
                cost[v]=cost[u]+wt;
                parent[v]=u;
                updated=true;
            }
        }
        if(updated==false){
            break;
        }
    }
    for(auto x:cost){
        cout<<x<<" ";
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<edge>Edges;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        Edges.push_back(edge(a,b,c));
    }
    belmenFord(Edges,v,e);
    return 0;
}