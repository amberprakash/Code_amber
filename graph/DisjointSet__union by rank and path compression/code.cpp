#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int findParent(int node,vector<int>&parent){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findParent(parent[node],parent);
}
void Union(int u,int v,vector<int>&rank,vector<int>&parent){
    u=findParent(u,parent);
    v=findParent(v,parent);

    if(rank[u]<rank[v]){
        parent[u]=v;
    }else if(rank[u]>rank[v]){
        parent[v]=u;
    }else{
        parent[v]=u;
        rank[u]++;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>parent(n+1);
    for(int i=1;i<n+1;i++){
        parent[i]=i;
    }
    vector<int>rank(n+1,0);
    int op;
    cin>>op;
    for(int i=0;i<op;i++){
        int u,v;
        cin>>u>>v;
        Union(u,v,rank,parent);
    }
    for(auto x:parent){
        cout<<x<<" ";
    }
}