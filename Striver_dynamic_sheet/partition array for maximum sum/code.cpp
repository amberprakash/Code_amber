#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums,int i,int k){
    if(i==nums.size()){
        return 0;
    }
    int n=nums.size();
    int maxE=INT_MIN;
    int ans=INT_MIN;
    int len=0;
    for(int ind=i;ind<min(i+k,n);ind++){
        len++;
        maxE=max(maxE,nums[ind]);
        int cost=(len*maxE)+solve(nums,ind+1,k);
        ans=max(ans,cost);
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<solve(nums,0,k);
    return 0;
}