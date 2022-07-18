#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// 0-indexing graph
bool bipartite(vector<vector<int>>&graph,vector<int>&color,int node,int n){
    queue<int>q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto &it:graph[curr]){
            if(color[it]==color[curr]){
                return false;
            }
            if(color[it]==-1){
                color[it]=1-color[curr];
                q.push(it);
            }
        }
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int>color(n,-1);
    int flag=0;
    
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(bipartite(graph,color,i,n)==false){
                cout<<"FALSE";
                flag=1;
                break;
            }
        }
    }
    if(flag==0){
        cout<<"TRUE";
    }
    return 0;
}