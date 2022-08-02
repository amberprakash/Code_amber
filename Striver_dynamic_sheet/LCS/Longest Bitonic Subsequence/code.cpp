#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr){
    int n=arr.size();
    vector<int>lcsf(n);
    vector<int>lcse(n);
    lcsf[0]=1;
    int ans=1;
    for(int i=1;i<n;i++){
        int mn=0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                mn=max(mn,lcsf[j]);
            }
        }
        lcsf[i]=max(lcsf[i],mn)+1;
        ans=max(ans,lcsf[i]);
    }
    lcse[n-1]=1;
    ans=0;
    for(int i=n-2;i>=0;i--){
        int mn=0;
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]){
                mn=max(mn,lcse[j]);
            }
        }
        lcse[i]=max(lcse[i],mn)+1;
        ans=max(ans,lcse[i]);
    }
    vector<int>total(n);
    ans=0;
    for(int i=0;i<n;i++){
        total[i]=lcse[i]+lcsf[i];
        ans=max(ans,total[i]);
    }
    return ans-1;
}
int main(){
    vector<int>arr={1,4,6,8,3,-2};
    cout<<solve(arr);
    return 0;
}