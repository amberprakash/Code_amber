#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// greatest Element smaller than x
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans=-1;
    int l=0;
    int h=n-1;
    while(l<=h){
        int mid= l+(h-l)/2;
        
        if(nums[mid]<=x){
            ans=mid;
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    cout<<ans;

    return 0;
}