#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    int sum=0;
    int ans=INT_MIN;
    for(i=0;i<k;i++){
        sum+=arr[i];
    }
    ans=max(ans,sum);
    int j=n-1;
    i--;
    while(i>=0){
        sum-=arr[i];
        i--;
        sum+=arr[j];
        j--;
        ans=max(ans,sum);
    }
    cout<<ans;


    return 0;
}