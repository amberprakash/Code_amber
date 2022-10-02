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
    unordered_map<int,int>mp;
    int sum=0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            ans=max(ans,i+1);
        }else if(mp.find(sum)!=mp.end()){
            ans=max(ans,i-mp[sum]);
        }else{
            mp[sum]=i;
        }
    }
    cout<<ans;
    return 0;
}