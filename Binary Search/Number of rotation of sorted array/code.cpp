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
    int l=0;
    int h=n-1;
    int ans=-1;
    while(l<=h){
        int mid = l + (h-l)/2;
        int nxt = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(arr[mid]<=arr[prev]  && arr[mid]<=arr[nxt]){
            ans=mid;
        }
        if(arr[mid]>arr[h]){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    cout<<ans;
    return 0;
}