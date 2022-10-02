#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mp[i-j].push(mat[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[i][j]=mp[i-j].top();
            mp[i-j].pop();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}