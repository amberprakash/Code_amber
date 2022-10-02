#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>&tree,int mid,int m){
    int n=tree.size();
    int sum=0;
    for(int i=0;i<n;i++){
        if(tree[i]-mid>0){
            sum+=tree[i]-mid;
            if(sum>=m){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>tree(n);
    for(int i=0;i<n;i++){
        cin>>tree[i];
    }
    int maxE=INT_MIN;
    for(auto x:tree){
        maxE=max(maxE,x);
    }

    int l=0;
    int h=maxE;
    int ans=-1;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(isValid(tree,mid,m)==true){
            ans=mid;
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    cout<<ans;
    return 0;
}