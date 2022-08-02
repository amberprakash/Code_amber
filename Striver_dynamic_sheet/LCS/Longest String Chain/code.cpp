#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b){
    return a.length()<b.length();
}
bool compare(string &a,string &b){
    int n=a.length();
    int m=b.length();
    int i=0,j=0;
    while(i<n){
        if(a[i]==b[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(i==n && j==m){
        return true;
    }
    return false;
}

int solve(vector<string>&arr){
    int n=arr.size();
    vector<int>dp(n);
    int ans=1;
    dp[0]=1;
    for(int i=1;i<n;i++){
        int mn=0;
        for(int j=0;j<i;j++){
            if(compare(arr[i],arr[j])){
                mn=max(mn,dp[j]);
            }
        }
        dp[i]=max(dp[i],mn)+1;
        ans=max(ans,dp[i]);
    }
    
    return ans;
}


int main(){
    vector<string>arr={"xbc","pcxbcf","xb","cxbc","pcxbc"};
    sort(arr.begin(),arr.end(),cmp);
    // for(auto x:arr){
    //     cout<<x<<" ";
    // }
    cout<<solve(arr);
    

    return 0;
}