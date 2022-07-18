#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else{
                int right=0;
                if(j>0){
                right=dp[i][j-1];
                }
                int down=0;
                if(i>0){
                    down=dp[i-1][j];
                }
                dp[i][j]=right+down;
            }
        }
    }
    cout<<dp[n-1][m-1];
    return 0;
}