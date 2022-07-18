#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solve(int e,int f,vector<vector<int>>&dp){
    if(f==0 || f==1){
        return f;
    }
    if(e==1){
        return f;
    }
    if(dp[e][f]!=-1){
        return dp[e][f];
    }
    int mn = INT_MAX;
    int low=0;
    int high=f;
    while(low<=high){
        int mid=(low+high)/2;
        int right=solve(e,f-mid,dp);// not break
        int left=solve(e-1,mid-1,dp);//break
        int temp=1+max(left,right);
        mn=min(mn,temp);
        if(right>left){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return dp[e][f]=mn;
}
int main(){
    int e,f;
    cin>>e>>f;
    vector<vector<int>>dp(e+1,vector<int>(f+1,-1));
    cout<<solve(e,f,dp);
    return 0;
}