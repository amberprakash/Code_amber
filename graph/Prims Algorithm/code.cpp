#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>>graph(v);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    vector<bool>visited(v,false);
    int n=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    int cost=0;
    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        if(visited[cur.second]==true){
            continue;
        }
        else{
            n++;
            cost+=cur.first;
            for(auto x:graph[cur.second]){
                pq.push({x.second,x.first});
            }
            visited[cur.second]=true;
        }
    }
    cout<<cost;
    return 0;
}