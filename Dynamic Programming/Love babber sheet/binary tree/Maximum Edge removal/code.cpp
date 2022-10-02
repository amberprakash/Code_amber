#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int ans;
int solve(vector<vector<int>>graph,int node,int parent,vector<bool>&visited){
    visited[node]=true;
    int total=0;
    for(auto x:graph[node]){
        if(x==parent || visited[x]==true){
            continue;
        }
        else{
            int temp=solve(graph,x,node,visited);
            if(temp%2==0){
                ans++;
            }
            total+=temp;
        }
    }
    return total+1;
}


int main(){
    int V;
    cin>>V;
    ans=0;
    vector<vector<int>>temp;
    for(int i=0;i<V-1;i++){
        vector<int>tip(2);
        cin>>tip[0]>>tip[1];
        temp.push_back(tip);
    }
    vector<vector<int>>graph(V+1);
    for(int i=0;i<temp.size();i++){
        graph[temp[i][0]].push_back(temp[i][1]);
        graph[temp[i][1]].push_back(temp[i][0]);
    }
    vector<bool>visited(V+1,false);
    solve(graph,1,-1,visited);
    cout<<ans;
    return 0;
}