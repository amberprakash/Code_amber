#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


bool isCycle(vector<vector<int>>graph,int node,vector<bool>&dfsvisited,vector<bool>&visited){
    visited[node]=true;
    dfsvisited[node]=true;
    for(auto x:graph[node]){
        if(!visited[x]){
            if(isCycle(graph,x,dfsvisited,visited)) return true;
        }else if(dfsvisited[x]){
            return true;
        }
    }
    dfsvisited[node]=false;
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
    }
    vector<bool>visited(v+1,false);
    vector<bool>dfsvisited(v+1,false);
    for(int i=1;i<=v;i++){
        if(visited[i]==false){
            if(isCycle(graph,i,dfsvisited,visited)){
                cout<<"Cycle Detected";
           }
        }
    }

    return 0;
}