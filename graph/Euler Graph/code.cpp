#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&graph,int node,vector<bool>&visited){
    visited[node]=true;
    for(auto x:graph[node]){
        if(!visited[x]){
            dfs(graph,x,visited);
        }
    }
}
bool connected(vector<vector<int>>&graph,int v,int e){
    vector<bool>visited(v,false);
    int node=-1;
    for(int i=0;i<v;i++){
        if(graph[i].size()>0){
            node=i;
            break;
        }
    }
    if(node==-1){
        return true;
    }
    dfs(graph,node,visited);

    for(int i=0;i<v;i++){
        if(visited[i]==false && graph[i].size()>0){
            return false;
        }
    }
    return true;

}
int solve(vector<vector<int>>&graph,int v,int e){
    if(!connected(graph,v,e)){
        return 0;
    }
    int odd;
    for(int i=0;i<v;i++){
        if(graph[i].size() & 1){
            odd+=1;
        }
    }
    if(odd>2){
        return 0;
    }
    if(odd==0){
        return 2;
    }
    return 1;
}
void findEuler(vector<vector<int>>&graph,int v,int e){
    int ans=solve(graph,v,e);
    if(ans==0){
        cout<<"Graph Is Not A Euler Graph";
    }else if(ans==1){
        cout<<"Graph Is Semi-Eulerian Graph";
    }else{
        cout<<"Graph Is Eulerian (Euler Circuit)";
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>graph(v);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    findEuler(graph,v,e);
    return 0;
}