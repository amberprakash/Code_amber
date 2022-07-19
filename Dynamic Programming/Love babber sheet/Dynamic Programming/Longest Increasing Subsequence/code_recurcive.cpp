#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,int ind,int prev_ind,int n,vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][prev_ind+1]!=-1){
        return dp[ind][prev_ind+1];
    }
    int temp;
    temp=solve(arr,ind+1,prev_ind,n,dp);
    if( prev_ind ==-1 || arr[ind]>arr[prev_ind]){
        temp=max(temp, 1+solve(arr,ind+1,ind,n,dp));
    }
    
    return dp[ind][prev_ind+1]=temp;
}



int main(){
    
    vector<int>arr={10,1,2,3,1,2,11,12,15,48,89};
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<solve(arr,0,-1,n,dp);
    
    
    
    return 0;
}