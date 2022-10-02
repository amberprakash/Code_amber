#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int u;
    int v;
    int wt;
    Node(int x,int y,int z){
        u=x;
        v=y;
        wt=z;
    }
};
bool cmp(Node a,Node b){
    return a.wt<b.wt;
}
int findPar(int node,vector<int>&parent){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findPar(parent[node],parent);
}
void Union(int u,int v,vector<int>&parent,vector<int>&rank){
    u=findPar(u,parent);
    v=findPar(v,parent);
    if(rank[u]>rank[v]){
        parent[v]=u;
    }else if(rank[u]<rank[v]){
        parent[u]=v;
    }else{
        parent[v]=u;
        rank[u]++;
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<Node>edges;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back(Node(a,b,c));
    }
    sort(edges.begin(),edges.end(),cmp);
    // for(auto x:edges){
    //     cout<<x.wt;
    // }
    vector<int>parent(v);
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    vector<int>rank(v,0);
    int cost=0;
    vector<pair<int,int>>mst;
    for(auto x:edges){
        if(findPar(x.u,parent)!=findPar(x.v,parent)){
            cost+=x.wt;
            mst.push_back({x.u,x.v});
            Union(x.u,x.v,parent,rank);
        }
    }
    cout<<cost;

    return 0;
}