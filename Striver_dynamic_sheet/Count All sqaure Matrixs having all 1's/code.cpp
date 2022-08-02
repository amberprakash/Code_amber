#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>>dp(n,(vector<int>(m)));
    for(int i=0;i<m;i++){
        dp[n-1][i]=mat[n-1][i];
    }
    for(int i=0;i<n;i++){
        dp[i][m-1]=mat[i][m-1];
    }
    int ans=0;
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if(mat[i][j]==0){
                dp[i][j]=0;
            }else{
                dp[i][j]=min(min(dp[i+1][j],dp[i+1][j+1]),dp[i][j+1])+1;
            }
            // ans=max(ans,dp[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=dp[i][j];
        }
        // cout<<endl;
    }
    cout<<ans;
    return 0;
}