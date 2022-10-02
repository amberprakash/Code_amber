#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// Peak element type question
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=-1;
    if(n==1){
        cout<<arr[0];
    }else{
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid= l + (h-l)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                ans=arr[mid];
                break;
            } else if(arr[mid+1]>arr[mid]){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        cout<<ans;
    }

    return 0;
}