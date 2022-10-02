#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={6,5,3,2,8,10,9};
    int k=3;
    int n=arr.size();
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>ans;

    int i=0;
    while(pq.size()<=k+1 && i<n){
        pq.push(arr[i++]);
        if(pq.size()==k+1){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}