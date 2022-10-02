#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int n=x.length();
    int m=y.length();
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int ans=0;
    ans+=(n-dp[n][m]);
    ans+=(m-dp[n][m]);
    cout<<ans;
    return 0;
}