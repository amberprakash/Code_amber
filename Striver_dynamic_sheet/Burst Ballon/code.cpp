#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mx=INT_MIN;
    for(int k=i;k<=j;k++){
        int cost= (arr[i-1]*arr[k]*arr[j+1])+solve(arr,i,k-1,dp)+solve(arr,k+1,j,dp);
        mx=max(mx,cost);
    }
    return dp[i][j]=mx;
}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr.push_back(1);
    arr.insert(arr.begin(),1);
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<solve(arr,1,n,dp);

    return 0;
}