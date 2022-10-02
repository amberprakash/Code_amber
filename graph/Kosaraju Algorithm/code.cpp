#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void dfs1(vector<vector<int>>&graph,int node,vector<bool>&visited,stack<int>&st){
    visited[node]=true;
    for(auto v:graph[node]){
        if(!visited[v]){
            dfs1(graph,v,visited,st);
        }
    }
    st.push(node);
}
void dfs2(vector<vector<int>>&graph,int node,vector<bool>&visited){
    cout<<node<<" ";
    visited[node]=true;
    for(auto v:graph[node]){
        if(!visited[v]){
            dfs2(graph,v,visited);
        }
    }
}
void reverse(vector<vector<int>>&graph,vector<vector<int>>&rev){
    int n=graph.size();
    for(int i=0;i<n;i++){
        for(auto x:graph[i]){
            rev[x].push_back(i);
        }
    }
}
void findSCC(vector<vector<int>>graph,int v,int e){
    stack<int>st;
    vector<bool>visited(v,false);
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            dfs1(graph,i,visited,st);
        }
    }
    vector<vector<int>>rev(v);
    reverse(graph,rev);
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    cout<<"strongly connected components"<<endl;
    while(!st.empty()){
        auto node=st.top();
        st.pop();
        if(visited[node]==false){
            dfs2(rev,node,visited);
            cout<<endl;
        }
    }
    
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>graph(v);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    findSCC(graph,v,e);
    return 0;
}