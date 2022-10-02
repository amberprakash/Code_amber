#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>graph(v+1);
    vector<int>inDegree(v+1,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        inDegree[b]++;
    }
    // for(auto x:inDegree){
    //     cout<<x<<" ";
    // }
    queue<int>q;
    vector<int>time(v+1);
    for(int i=1;i<v+1;i++){
        if(inDegree[i]==0){
            q.push(i);
            time[i]=1;
        }
    }
    
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        for(auto x:graph[cur]){
            inDegree[x]--;
            if(inDegree[x]==0){
                q.push(x);
                time[x]=time[cur]+1;
            }
        }
    }
    for(int i=1;i<v+1;i++){
        cout<<time[i]<<" ";
    }
    return 0;
}