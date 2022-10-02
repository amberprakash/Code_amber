#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int maxE=INT_MIN;
    int minE=INT_MAX;
    for(auto x:nums){
        maxE=max(maxE,x);
        minE=min(minE,x);
    }
    int l=minE;
    int h=maxE;
    int ans;
    while(l<=h){
        int mid= l +(h-l)/2;
        int countless=0;
        int countequal=0;
        for(int i=0;i<n;i++){
            if(nums[i]<mid){
                countless++;
            }else if(nums[i]==mid){
                countequal++;
            }
        }

        if(countless < k && countless+countequal>=k ){
            ans= mid;
            break;
        }else if(countless>=k){
            h=mid-1;
        }else if(countless<k && countless+countequal<k){
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}