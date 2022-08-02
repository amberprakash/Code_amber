#include<iostream>
#include<vector>
#include<bits/stdc++.h>
//LeetCode 351
using namespace std;
int arr[100002];
void merge(vector<pair<int,int>>&pairs,int low,int mid,int high){
        int i=low;
        int j=mid;
        int count=0;
        vector<pair<int,int>>temp(high-low+1);
        int k=0;
        while(i<=mid-1 && j<=high){
            if(pairs[i].first<=pairs[j].first){
                arr[pairs[i].second]+=count;
                temp[k++]={pairs[i++]};
            }else{
                count++;
                temp[k++]={pairs[j++]};
            }
        }
        while(i<=mid-1){
            arr[pairs[i].second]+=count;
            temp[k++]={pairs[i++]};
        }
        while(j<=high){
            temp[k++]={pairs[j++]};
        }
        
        for(int i=0;i<k;i++){
            pairs[low++]=temp[i];
        }
        
    }

void merge_sort(vector<pair<int,int>>&pairs,int low,int high){
        int mid=(low+high)/2;
        if(low < high){
            merge_sort(pairs,low,mid);
            merge_sort(pairs,mid+1,high);
            
            merge(pairs,low,mid+1,high);
        }
    }

vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>pairs;
        for(int i=0;i<n;i++){
            pairs.push_back({nums[i],i});       
        }
        merge_sort(pairs,0,n-1);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=arr[i];
        }
        return ans;
        
    }    
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans;
    ans=countSmaller(nums);
    for(auto x:ans){
        cout<<x<<" ";
    }


    return 0;

}