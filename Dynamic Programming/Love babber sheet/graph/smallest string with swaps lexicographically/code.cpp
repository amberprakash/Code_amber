#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// link=https://leetcode.com/problems/smallest-string-with-swaps/

void dfs(string s,int i,vector<char>&characters,vector<int>&indecis,vector<vector<int>>&graph,vector<bool>&visited){
     characters.push_back(s[i]);
     indecis.push_back(i);
     visited[i]=true;
     for(auto &it:graph[i]){
         if(visited[it]==false){
             dfs(s,it,characters,indecis,graph,visited);
         }
     }
}
int main(){
    string s;
    cin>>s;
    vector<pair<int,int>>pairs;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pairs.push_back({a,b});
    }
    int v=s.size();
    vector<vector<int>>graph(v);
    for(int i=0;i<n;i++){
        graph[pairs[i].first].push_back(pairs[i].second);
        graph[pairs[i].second].push_back(pairs[i].first);
    }

    
    vector<bool>visited(v,false);
    
    for(int i=0;i<v;i++){
        vector<char>characters;
        vector<int>indecis;

        if(visited[i]==false){
            dfs(s,i,characters,indecis,graph,visited);

            sort(characters.begin(),characters.end());
            sort(indecis.begin(),indecis.end());

            for(int j=0;j<indecis.size();j++){
                s[indecis[j]]=characters[j];
                
            }

        }
    }
    cout<<s;
    return 0;
}