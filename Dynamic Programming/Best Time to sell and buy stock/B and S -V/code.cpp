#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr,int i,int buy,int n){
    if(i>=n){
        return 0;
    }
    int profit=0;
    if(buy){
        profit = max( -arr[i] + solve(arr,i+1,0,n),
                        0+solve(arr,i+1,1,n));
    }else{
        profit= max( arr[i]+solve(arr,i+2,1,n),
                           0+ solve(arr,i+1,0,n)     );
    }
    return profit;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,0,1,n);
    return 0;
}