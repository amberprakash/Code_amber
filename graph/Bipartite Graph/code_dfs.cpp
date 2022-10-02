#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>graph,int node,vector<int>&color,int col){
    color[node]=1;
    for(auto x:graph[node]){
        if(color[x]==-1){
            if(dfs(graph,x,color,1-color[node])==false){
                return false;
            }
        }else if(color[x]==color[node]){
            return false;
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
            if(dfs(graph,i,color,1)==false){
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