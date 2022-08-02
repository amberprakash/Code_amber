#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solve_left(vector<int>&nums,int target){
    int l=0;
    int h=nums.size()-1;
    int res=-1;
    while(l<=h){
        int mid= l + (h-l)/2;
        if(nums[mid]==target){
            res=mid;
            h=mid-1;
        }
        else if(nums[mid]>target){
            h=mid-1;
        }else{
            l=mid+1;
        }

    }
    return res;
}
int solve_right(vector<int>&nums,int target){
    int l=0;
    int h=nums.size();
    int res=-1;
    while(l<=h){
        int mid=l +(h-l)/2;
        if(nums[mid]==target){
            res=mid;
            l=mid+1;
        }
        if(nums[mid]>target){
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return res;
}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<solve_left(nums,target)<<" "<<solve_right(nums,target);
    return 0;
}