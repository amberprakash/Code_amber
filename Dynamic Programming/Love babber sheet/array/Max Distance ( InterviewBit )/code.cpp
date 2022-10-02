#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        vec.push_back({nums[i],i});
    }
    sort(vec.begin(),vec.end());
    int min_ind=INT_MAX;
    int temp=0;
    for(int i=0;i<n;i++){
        min_ind=min(min_ind,vec[i].second);
        temp=max(temp,vec[i].second-min_ind);
    }
    cout<<temp;
    return 0;
}