#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr,int i,int buy,int k,int n,vector<vector<vector<int>>>&dp){
    if(i==n || k==0){
        return 0;
    }
    if(dp[i][buy][k]!=-1){
        return dp[i][buy][k];
    }
    int profit=0;
    if(buy){
        profit =max(  -arr[i]+solve(arr,i+1,0,k,n,dp),
                        0 + solve(arr,i+1,1,k,n,dp)    );
    }else{
        profit =max(arr[i]+solve(arr,i+1,1,k-1,n,dp),
                            0+solve(arr,i+1,0,k,n,dp)    );
    }
    return dp[i][buy][k]=profit;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
    cout<<solve(arr,0,1,k,n,dp);

    return 0;
}