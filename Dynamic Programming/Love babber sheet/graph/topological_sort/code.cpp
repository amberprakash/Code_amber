#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&graph,int node,vector<bool>&visited,stack<int>&st){
    visited[node]=true;
    for(auto x:graph[node]){
        if(visited[x]==false){
            dfs(graph,x,visited,st);
        }
    }
    st.push(node);
    return;
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
    stack<int>st;
    for(int i=1;i<=v;i++){
        if(visited[i]==false){
            dfs(graph,i,visited,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }


    return 0;
}