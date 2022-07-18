#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    vector<int>job(n+1);
    vector<vector<int>>graph(n+1);
    vector<int>indegree(n+1,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    // for(int i=1;i<n+1;i++){
    //     cout<<indegree[i]<<" ";
    // }
    queue<int>q;
    for(int i=1;i<n+1;i++){
        if(indegree[i]==0){
            q.push(i);
            job[i]=1;
        }
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto u:graph[cur]){
            indegree[u]--;
            if(indegree[u]==0){
                job[u]=job[cur]+1;
                q.push(u);
            }
        }

    }
    for(int i=1;i<n+1;i++){
        cout<<job[i]<<" ";
    }

    return 0;
}