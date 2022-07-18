#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int temp=INT_MIN;
int solve(vector<vector<int>>&t,int i,int j,int n,int m,vector<vector<int>>&visited){
   if(i<0  || j<0 || i>=n || j>=m || t[i][j]==0 || visited[i][j]==1){
       return;
   }
   int X[4]={1,-1,0,0};
   int Y[4]={0,0,1,-1};
   for(int k=0;k<4;k++){
       visited[i][j]=1;
       solve(t,i+X[k],j+Y[k],n,m,visited);
       visited[i][j]=0;
   }

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>t(n,vector<int>(m));
    vector<vector<int>>visited(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>t[i][j];
        }
    }

    return 0;
}