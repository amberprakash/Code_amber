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
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        vec.push_back({arr[i],i});
    }
    sort(vec.begin(),vec.end());
    int ans=INT_MIN;
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        mini=min(mini,vec[i].second);
        ans=max(ans,vec[i].second-mini);
    }
    cout<<ans;


    return 0;

}