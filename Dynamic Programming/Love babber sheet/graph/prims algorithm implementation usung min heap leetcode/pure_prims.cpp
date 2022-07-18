#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int minCost(vector<pair<pair<int,int>,int>>&graph,int n,int m){
    vector<bool>inMst(n,false);
    

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;

    int mstCost=0;
    int edgeUsed=0;
    heap.push({0,0});
    

    while(edgeUsed<n){
       pair<int,int>topElement=heap.top();
       heap.pop();
       int weight=topElement.first;
       int currNode=topElement.second;
       if(inMst[currNode]){
           continue;
       }
       inMst[currNode]=true;
       mstCost+=weight;
       edgeUsed++;
       for(int i=0;i<2*m;i++){
           if(currNode==graph[i].first.first){
               if(!inMst[graph[i].first.second]){
                     heap.push({graph[i].second,graph[i].first.second});

               }
           }
       }
    }
    return mstCost;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,int>>graph;
    // unordered_map<int,int>hash;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph.push_back({{a,b},c});
        graph.push_back({{b,a},c});
        // hash[a]++;
        // hash[b]++;
    }
    cout<<minCost(graph,n,m);

    return 0;
}