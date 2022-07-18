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
    sort(arr.begin(),arr.end());
    int smallest=arr[0]+k;
    int largest=arr[n-1]-k;
    int ans=largest-smallest;
    int mint,maxt;
    for(int i=0;i<n-1;i++){
         mint=min(smallest,arr[i+1]-k);
         maxt=max(largest,arr[i]+k);
         if(mint<0){
             continue;
         }
        ans=min(ans,maxt-mint);
    }
    cout<<ans;
    return 0;
}