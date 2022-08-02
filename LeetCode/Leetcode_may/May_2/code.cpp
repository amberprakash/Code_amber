#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
     n=nums.size();
       for(int i=0,j=0;i<n;i++){
           if(nums[i]%2==0){
               swap(nums[j++],nums[i]);
           }
       }
    return 0;
}