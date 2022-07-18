#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    // vector<vector<int>>dp(n+1,vector<int>(2,0));
    vector<int>ahead(2,0),curr(2,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // dp[n][0]=dp[n][1]=0;
    ahead[0]=ahead[1]=0;
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
            if(buy){
                profit=max( -arr[i]+ahead[0],//buy stock
                                0+ahead[1]);// not buy move to next day
            }else{
                profit=max( arr[i]+ahead[1],// sell stock
                                        0+ ahead[0]);// not sell and move to next stock
            }
            curr[buy]=profit;
        }
        ahead=curr;
    }
    cout<<ahead[1];
    return 0;
}