#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string s,int i,int n,vector<int>&dp){
    if(i==n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=INT_MAX;
    for(int j=i;j<n;j++){
        if(isPalindrome(s,i,j)){
            int cost=1+solve(s,j+1,n,dp);
            ans=min(ans,cost);
        }
    }
    return dp[i]=ans;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<int>dp(n,-1);
    cout<<solve(s,0,n,dp)-1;
    return 0;
}