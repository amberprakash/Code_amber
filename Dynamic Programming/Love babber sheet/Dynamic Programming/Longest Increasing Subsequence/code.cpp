#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// Recursive Code
int solve(vector<int>arr,int i,int n){
    if(i==n-1){
        return 0;
    }
    int temp=0;
    int ans=0;
    for(int k=i+1;k<n;k++){
        if(arr[k]>arr[i]){
            int temp=1+solve(arr,k,n);
            ans=max(temp,ans);
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int temp=1+solve(arr,i,n);
        ans=max(temp,ans);
    }
    cout<<ans;
    
    return 0;
}