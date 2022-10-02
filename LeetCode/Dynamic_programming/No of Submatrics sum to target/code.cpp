#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int total;
unordered_map<int,int>mp;
void solve(vector<int>arr,int target){
    int n=arr.size();
    mp.clear();
    int sum=0;
    for(auto x:arr){
        sum+=x;
        if(sum==target){
            total++;
        }
        if(mp.find(sum-target)!=mp.end()){
            total+=mp[sum-target];
        }
        mp[sum]++;
    }
}


int main(){
    int n,m,target;
    total=0;
    cin>>n>>m>>target;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<m;i++){
        vector<int>temp(n,0);
        for(int j=i;j<m;j++){
            for(int k=0;k<n;k++){
                temp[k]+=mat[k][j];
            }
            solve(temp,target);
        }
    }
    cout<<total;
    return 0;
}