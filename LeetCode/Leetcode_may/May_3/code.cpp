#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// Shortest Unsorted Continuous Subarray
// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
// then the whole array will be sorted in ascending order.

//Return the shortest such subarray and output its length.
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>temp;
    temp=arr;
    sort(temp.begin(),temp.end());
    int low=INT_MAX;
    int high=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]!=temp[i]){
            low=min(low,i);
            high=max(high,i);
        }
    }
    cout<<high-low+1;
    return 0;
}