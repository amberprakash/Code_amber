#include <iostream>
#include<bits/stdc++.h>

#define INF 10000000
using namespace std;

int main()
{
    vector<int>A={2,3,1,5,4};
    vector<int>B={3,2,4,1};
    vector<int>C={1,2,5,10};
    int sum=-1;
    for(int i=0;i<A.size();i++){
        sum=max(sum,A[i]);
    }
    int ans=0;
    int n=B.size();
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j==0){
                dp[i][j]=0;
            }
            else if(i==0){
                dp[i][j]=INF;
            }
            else{
                if(B[i-1]<=j){
                    dp[i][j]=min(C[i-1]+dp[i][j-B[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
            
        }
    }
    for(int i=0;i<A.size();i++){
        ans+=dp[n][A[i]];
    }
    cout<<ans;

    return 0;
}