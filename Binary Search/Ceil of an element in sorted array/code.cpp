#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// smallest element greater than x
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
        int mid =  l +(h-l)/2;
        if(arr[mid]==x){
            ans=mid;
            break;
        }
        else if(arr[mid]>x){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;

    return 0;
}