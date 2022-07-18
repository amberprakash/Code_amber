#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string x;
    cin>>x;
    int n=x.length();
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++){
        dp[i][i]=1;
    }
    int maxlength=1;
    int start;
    for(int i=0;i<n-1;i++){
        if(x[i]==x[i+1]){
            dp[i][i+1]=1;
            maxlength=2;
            start=i;
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i+k-1;
            if(x[i]==x[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
                if(k>maxlength){
                    maxlength=k;
                    start=i;
                }
            }
        }
    }
    cout<<maxlength;
    for(int i=start;i<maxlength+start;i++){
        cout<<x[i];
    }

    return 0;
}