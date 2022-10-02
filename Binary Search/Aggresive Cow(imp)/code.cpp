#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>&pos,int k,int mid){
    int n=pos.size();
    int start=pos[0];
    int cow=1;
    for(int i=1;i<n;i++){
        if(pos[i]-start>=mid){
            cow++;
            start=pos[i];
        }
        
    }
    if(cow<k){
        return false;
    }
    return true;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>pos(n);
    for(int i=0;i<n;i++){
        cin>>pos[i];
    }
    sort(pos.begin(),pos.end());
    int l=1;
    int h=pos[n-1];
    int ans=-1;
    while(l<=h){
        int mid= l +(h-l)/2;
        if(isValid(pos,k,mid)==true){
            ans=mid;
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    cout<<ans;
    return 0;
}