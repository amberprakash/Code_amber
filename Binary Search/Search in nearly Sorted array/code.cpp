#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0;
    int h=n-1;
    int ans=-1;
    while(l<=h){
        int mid=(l + (h-l)/2);
        if(arr[mid]==x){
            ans=mid;
            break;
        }else if( mid-1>=l &&  arr[mid-1]==x){
            ans=mid-1;
            break;
        }
        else if( mid+1<=h  && arr[mid+1]==x){
            ans=mid+1;
            break;
        }else if(arr[mid]>x){
            h=mid-2;
        }else{
            l=mid+2;
        } 
    }
    cout<<ans;
    return 0;
}