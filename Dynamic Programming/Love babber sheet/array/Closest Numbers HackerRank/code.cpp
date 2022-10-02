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
    sort(nums.begin(),nums.end());
    int diff=nums[1]-nums[0];
    for(int i=2;i<n;i++){
        diff=min(diff,nums[i]-nums[i-1]);
    }
    for(int i=1;i<n;i++){
        if(nums[i]-nums[i-1]==diff){
            cout<<nums[i]<<" "<<nums[i-1]<<endl;
        }
    }
    cout<<diff;

    return 0;
}