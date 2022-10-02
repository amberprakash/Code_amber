#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//using bfs topological sort method   //// khan methods
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
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        cnt++;
        q.pop();
        for(auto x:graph[node]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
    if(cnt==v){
        cout<<"false";
    }else{
        cout<<"true";
    }
    return 0;
}