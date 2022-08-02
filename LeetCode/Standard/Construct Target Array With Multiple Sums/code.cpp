#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// leetcode 1354

bool solve(vector<int>nums){
    int n=nums.size();
    int sum=0;
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        pq.push(nums[i]);
    }

    while(pq.top()!=1){
        sum-=pq.top();
        if(sum==0 || sum>=pq.top()){
            return false;
        }
        int old=pq.top()%sum;
        if(old==0 && sum!=1){
            return false;
        }
        pq.pop();
        pq.push(old);
        sum+=old;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    if(solve(nums)){
        cout<<"TRUE";
    }else{
        cout<<"FALSE";
    }
    return 0;
}