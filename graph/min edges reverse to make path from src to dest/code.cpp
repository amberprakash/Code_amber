#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>>Edges;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        Edges.push_back({a,b});
    }
    unordered_map<int,vector<pair<int,int>>>graph;
    for(int i=0;i<e;i++){
        graph[Edges[i][0]].push_back({Edges[i][1],0});
        graph[Edges[i][1]].push_back({Edges[i][0],1});
    }
    int src,dst;
    cin>>src>>dst;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    pq.push({0,src});
    vector<int>cost(v,INT_MAX);
    cost[src]=0;
    vector<int>visited(v,0);
    while(!pq.empty()){
        auto node=pq.top();
        pq.pop();
        int u=node[1];
        int wt=node[0];
        if(!visited[u]){
            visited[u]=1;
            for(auto x:graph[u]){
                if(wt+x.second < cost[x.first]){
                    cost[x.first]=wt+x.second;
                    pq.push({cost[x.first],x.first});
                }
            }
        }
    }
    cout<<cost[dst];
    

    return 0;
}