#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    vector<vector<int>>after(2,vector<int>(3,0));
    vector<vector<int>>curr(2,vector<int>(3,0));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int k=0;k<=2;k++){
                int profit=0;
                if(buy){
                    profit = max( -prices[i] + after[0][k],
                                       0 + after[1][k]);
                }else{
                    profit = max( prices[i] + after[1][k-1],
                                       0   + after[0][k]);
                }
                curr[buy][k]=profit;
            }
            after=curr;
        }
    }
    cout<<after[1][2];

    return 0;
}       