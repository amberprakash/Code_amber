#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<pair<int,int>>nums(n);
    for(int i=0;i<n;i++){
        nums[i]={arr[i],i};
    }
    sort(nums.begin(),nums.end());
    int ans=0;
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(visited[i]==true || nums[i].second==i){
            continue;
        }
        int cl=0;
        int j=i;
        while(visited[j]==false){
            visited[j]=true;
            cl++;
            j=nums[j].second;
        }
        ans+=cl-1;
    }
    cout<<ans;
    return 0;
}