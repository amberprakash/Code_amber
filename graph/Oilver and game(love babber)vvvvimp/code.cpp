#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&graph,vector<bool>&visited,vector<int>&ind,vector<int>&outd,int &time){
    visited[node]=1;
    ind[node]=time++;
    for(auto x:graph[node]){
        if(!visited[x]){
            dfs(x,graph,visited,ind,outd,time);
        }
    }
    outd[node]=time++;
}
bool check(int x,int y,vector<int>&ind,vector<int>&outd){ // to check weather x is in y subtree or not
    if(ind[x]>ind[y] && outd[x]<outd[y]){
        return 1;
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vector<int>ind(n+1);
    vector<int>outd(n+1);
    int time=0;
    vector<bool>visited(n+1,false);
    dfs(1,graph,visited,ind,outd,time);
    
    int q;
    cin>>q;
    while(q--){
        int type,x,y;
        cin>>type;
        cin>>x;
        cin>>y;
        if(!check(x,y,ind,outd) && !check(y,x,ind,outd)){
            cout<<"NO"<<endl;
            continue;
        }
        if(type==1){
            if(check(x,y,ind,outd)==1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            if(check(y,x,ind,outd)==1){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}