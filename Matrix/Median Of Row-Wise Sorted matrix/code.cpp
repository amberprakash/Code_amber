#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&temp,int x){
    int l=0;
    int h=temp.size()-1;
    while(l<=h){
        int mid = l +(h-l)/2;
        if(temp[mid]<=x){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return l;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int l=1;
    int h=1e9;
    while(l<=h){
        int mid = l +(h-l)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=solve(mat[i],mid);
        }
        if(cnt<=(n*m)/2){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    cout<<l;
    return 0;
}