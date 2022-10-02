#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>graph(v+1);
    vector<int>indegree(v+1,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int>q;
    for(int i=1;i<v+1;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto x:graph[node]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}