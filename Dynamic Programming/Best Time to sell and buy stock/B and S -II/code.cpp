#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// In this question we can buy as many stock but condition is we to sell it before buying another stock 
// we cannot buy 2 stock at the same time
// buy ==1 (it means we can buy stock)
// buy ==0 (it means we have to sell it)
int solve(vector<int>&arr,int i,int n,int buy){
    if(i==n){
        return 0;
    }
    int profit=0;
    if(buy){
        profit=max( -arr[i]+solve(arr,i+1,n,0),//buy stock
                        0+solve(arr,i+1,n,1));// not buy move to next day
    }else{
        profit=max( arr[i]+solve(arr,i+1,n,1),// sell stock
                                0+ solve(arr,i+1,n,0));// not sell and move to next stock
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
    cout<<solve(arr,0,n,1);

    return 0;
}