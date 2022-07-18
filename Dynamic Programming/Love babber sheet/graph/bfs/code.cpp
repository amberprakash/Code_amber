#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void bfsofGraph(vector<int>adj[],int n,vector<int>&ans){
        queue<int>q;
        bool visited[n]={0};
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int currnode=q.front();
            q.pop();
            ans.push_back(currnode);
            for(auto &i:adj[currnode]){
                if(visited[i]!=1){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>temp;
    bfsofGraph(adj,V,temp);
    for(auto &i:temp){
        cout<<i<<" ";
    }
    return 0;
}