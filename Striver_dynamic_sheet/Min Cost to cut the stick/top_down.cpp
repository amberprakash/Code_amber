#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&cuts,int i,int j,vector<vector<int>>&dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn=INT_MAX;
    for(int k=i;k<=j;k++){
        int temp=cuts[j+1]-cuts[i-1] + solve(cuts,i,k-1,dp)+solve(cuts,k+1,j,dp);
        mn=min(mn,temp);
    }
    return dp[i][j]=mn;
}

int main(){
    int N;
    cin>>N;
    int c;
    cin>>c;
    vector<int>cuts(c);
    for(int i=0;i<c;i++){
        cin>>cuts[i];
    }
    cuts.push_back(N);
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    vector<vector<int>>dp(c+2,vector<int>(c+2,0));
    for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(i>j){
                continue;
            }
            int mn=INT_MAX;
            for(int k=i;k<=j;k++){
                int cost= cuts[j+1]-cuts[i-1] + dp[i][k-1]+dp[k+1][j];
                mn=min(mn,cost);
            }
            dp[i][j]=mn;
            }
    }
    cout<<dp[1][c];
    //cout<<solve(cuts,1,c,dp);
    return 0;
}