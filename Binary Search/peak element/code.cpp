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
    int ans=-1;
    if (n==1){
        cout<<arr[0];
    }else if(arr[0]>arr[1]){
        cout<<arr[0];
    }else if(arr[n-1]>arr[n-2]){
        cout<<arr[n-1];
    }else{
        int l=1;
        int h=n-2;
        while(l<=h){
            int mid= l +(h-l)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                ans=arr[mid];
                break;
            }else if(arr[mid+1]>arr[mid]){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        cout<<ans;
    }
    return 0;
}