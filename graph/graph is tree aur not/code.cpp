#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool isCycle(int node,int parent,vector<vector<int>>&graph,vector<bool>&visited){
    visited[node]=true;
    for( auto v:graph[node]){
        if(visited[v]==false){
            if(isCycle(v,node,graph,visited)==true)return true;
        }else if(visited[v]==true && v!=parent){
            return true;
        }
    }
    return false;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>>graph(V+1);
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool flag=0;
    vector<bool>visited(V,false);
    for(int i=1;i<=V;i++){
        if(visited[i]==false){
            if(isCycle(i,-1,graph,visited)==true){
                cout<<"TRUE";
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        cout<<"FALSE";
    }
    return 0;
}