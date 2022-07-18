#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int numDistinct(string A, string B) {
    int m=A.length();
    int n=B.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1));

    for(int j=0;j<=m;j++){
        dp[0][j]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int sol1=dp[i][j-1];
            int sol2=0;
            if(B[i-1]==A[j-1]){
                sol2=dp[i-1][j-1];
            }
            dp[i][j]=sol1+sol2;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}

int main(){
    string X,Y;
    cin>>X>>Y;
    cout<<numDistinct(X,Y);
    return 0;
}