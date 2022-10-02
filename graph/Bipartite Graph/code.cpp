#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>graph,int node,vector<int>&color){
    queue<int>q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        for(auto x:graph[cur]){
            if(color[x]==-1){
                color[x]=1-color[cur];
                q.push(x);
            }else if(color[cur]==color[x]){
                return false;
            }
        }
    }
    return true;
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
    vector<int>color(v+1,-1);
    int flag=0;
    for(int i=1;i<v+1;i++){
        if(color[i]==-1){
            if(isBipartite(graph,i,color)==false){
                cout<<"False";
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        cout<<"True";
    }
    return 0;
}