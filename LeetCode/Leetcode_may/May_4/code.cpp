#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans=0;
    unordered_map<int,int>mp;
    for(auto &it:nums){
        int a=k-it;
        if(mp[a]>0){
            ans+=1;
            mp[a]--;
        }
        else{
            mp[it]++;
        }

    }
    cout<<ans;
    return 0;
}