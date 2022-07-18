#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solve(int n,int m,vector<vector<int>>&t){
    if(n==0 && m==0){
        return 1;
    }
    if(n<0 || m<0){
        return 0;
    }
    if(t[n][m]!=-1){
        return t[n][m];
    }
    int left=solve(n,m-1,t);
    int up=solve(n-1,m,t);
    return t[n][m]=left+up;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>t(n,vector<int>(m,-1));
    cout<<solve(n-1,m-1,t);
    return 0;
}