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
    int temp=INT_MAX;
    int l=0;
    int h=n-1;
    while(l<=h){
        int mid = l +(h-l)/2;
        if(arr[mid]==x){
            temp=0;
            break;
        }else if(arr[mid]>x){
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    
    temp=min(temp,abs(arr[l]-x));
    temp=min(temp,abs(arr[h]-x));
    cout<<temp;
    return 0;
}