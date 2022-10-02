#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>>&graph,int node ,int parent,vector<bool>&visited){
    visited[node]=true;
    for(auto x:graph[node]){
        if(visited[x]==false){
            if(isCycle(graph,x,node,visited)==true) return true;
        }else if(x!=parent){
            return true;
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
    int flag=0;
    for(int i=1;i<=v;i++){
        if(visited[i]==false){
            if(isCycle(graph,i,-1,visited)){
                flag=1;
                cout<<"Cycle Detected";
                break;
            }
        }
    }
    if(flag==0){
        cout<<"Cycle does not exists";
    }
    return 0;
}