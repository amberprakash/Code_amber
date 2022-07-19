#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lcs;
        lcs.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>lcs.back()){
                lcs.push_back(nums[i]);
                len++;
            }else{
                int ind = lower_bound(lcs.begin(),lcs.end(),nums[i]) - lcs.begin();
                lcs[ind]=nums[i];
            }
        }
        return len;
    }
int main(){
    vector<int>arr={1,2,3,-11,-5};
    cout<<lengthOfLIS(arr);
    return 0;
}