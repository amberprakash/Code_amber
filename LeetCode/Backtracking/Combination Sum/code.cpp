#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void solve(vector<int>&arr,int target,int ind,vector<int>&temp){
    if(target==0){
        ans.push_back(temp);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=ind;i<arr.size();i++){
        temp.push_back(arr[i]);
        solve(arr,target-arr[i],i,temp);
        temp.pop_back();
    }
    return;
}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>temp={};
    solve(arr,target,0,temp);
    for(auto &x:ans){
        for(int i=0;i<x.size();i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}