#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],int s,vector<bool>&visited,vector<int>&ans){
    visited[s]=true;
    ans.push_back(s);
    for(auto t:adj[s]){
        if(!visited[t]){
            dfs(adj,t,visited,ans);
        }
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<int>adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>ans;
    vector<bool>visited(V);
    dfs(adj,0,visited,ans);
    for(auto &t:ans){
        cout<<t<<" ";
    }
    return 0;
}