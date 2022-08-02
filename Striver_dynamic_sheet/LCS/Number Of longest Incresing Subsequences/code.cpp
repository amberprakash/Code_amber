#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr){
    int n=arr.size();
    vector<int>lcs(n);
    vector<int>count(n+1,0);
    lcs[0]=1;
    count[1]=1;
    for(int i=1;i<n;i++){
        int mn=0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                mn=max(mn,lcs[j]);
            }
        }
        lcs[i]=max(lcs[i],mn)+1;
        count[lcs[i]]++;
    }
    int ans=INT_MIN;
    for(auto x:count){
        ans=max(ans,x);
    }
    return ans;
}
int main(){
    vector<int>arr={1,3,5,4,7};
    cout<<solve(arr);
    return 0;
}