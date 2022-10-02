#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>>&graph,int node,int parent,vector<bool>&visited){
    visited[node]=true;

    queue<pair<int,int>>q;
    q.push({node,parent});

    while(!q.empty()){
        int v=q.front().first;
        int par=q.front().second;
        for(auto x:graph[v]){
            if(visited[x]==false){
                visited[x]=true;
                q.push({x,v});
            }else if(x!=par){
                return true;
            }
        }
    }
    return false;

}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>graph(v+1);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool>visited(v+1,false);
    for(int i=1;i<=v;i++){
        if(visited[i]==false){
            if(isCycle(graph,i,-1,visited)){
                cout<<"Cycle Detected";
                break;
            }
        }
    }
    return 0;
}