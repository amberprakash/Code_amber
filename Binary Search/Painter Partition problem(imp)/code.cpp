#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>&arr,int n,int k,long long mid){
        int sum=0;
        int painter=1;
        for(int i=0;i<n;i++){
            if(arr[i]>mid){
                return false;
            }
            if(sum+arr[i]>mid){
                painter++;
                sum=arr[i];
                if(painter>k){
                    return false;
                }
            }else{
                sum+=arr[i];
            }
        }
        return true;
    }
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        long long l=0;
        long long h=sum;
        long long ans=-1;
        while(l<=h){
            long long mid = l +(h-l)/2;
            if(isValid(arr,n,k,mid)==true){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans;
    return 0;
}