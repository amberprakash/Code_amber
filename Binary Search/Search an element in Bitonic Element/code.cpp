#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int incBS(vector<int>&arr,int l,int h,int x){
    int ans=-1;
    while(l<=h){
        int mid=l + (h-l)/2;
        if(arr[mid]==x){
            return mid;
        }else if(arr[mid]>x){
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}

int decBS(vector<int>&arr,int l,int h,int x){
    int ans=-1;
    while(l<=h){
        int mid= l +(h-l)/2;
        if(arr[mid]==x){
            return mid;
        }else if(arr[mid]>x){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return ans;
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0;
    int h=n-1;
    int peak;
    while(l<=h){
        int mid= l +(h-l)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            peak=mid;
            break;
        }else if(arr[mid+1]>arr[mid]){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    int a=incBS(arr,0,peak-1,x);
    int b=decBS(arr,peak,n-1,x);
    cout<<a<<" "<<b;

    return 0;
}