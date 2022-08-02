#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,target;
    cin>>n>>target;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int ans=INT_MIN;
    int min_diff=INT_MAX;
    for(int i=0;i<n-2;i++){
        int front=i+1;
        int back=n-1;
        while(front<back){
            int sum=nums[i]+nums[front]+nums[back];
            if(abs(target-sum)<min_diff){
                min_diff=abs(target-sum);
                ans=sum;
            }else if(sum>target){
                back--;
            }else{
                front++;
            }
        }
    }
    cout<<ans;
    return 0;
}