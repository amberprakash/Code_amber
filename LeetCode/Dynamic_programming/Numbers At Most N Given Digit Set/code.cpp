#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    string target;
    cin>>target;
    int k=target.length();
    vector<int>dp(k+1);
    dp[k]=1;
    for(int i=k-1;i>=0;i--){
        int t=target[i]-'0';
        for(auto x:arr){
            if(x<t){
                dp[i]+=pow(n,k-i-1);
            }else if(t==x){
                dp[i]+=dp[i+1];
            }
        }
    }
    //case-1
    for(int i=1;i<k;i++){
        dp[0]+=pow(n,i);
    }
    cout<<dp[0];
}