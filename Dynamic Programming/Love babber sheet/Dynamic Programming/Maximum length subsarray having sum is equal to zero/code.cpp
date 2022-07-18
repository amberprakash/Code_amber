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
    int ans=INT_MIN;
    int temp=0;
    for(int i=0;i<n;i++){
        temp+=arr[i];
        if(temp==0){
            ans=max(ans,i+1);
        }
        if(mp.find(temp)==mp.end()){
            mp[temp]=i;
        }
        else{
            ans=max(ans,i-mp[temp]);
        }
    }
    cout<<ans;
    return 0;
}