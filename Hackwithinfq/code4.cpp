#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int max_count=0;
void solve(vector<int>arr,int n,int k,int ind,int count){
    if(ind>=n){
        return ;
    }
    int flag=0;
    if(count>max_count){
        max_count=count;
    }
    for(int i=ind+1;i<=k+ind;i++){
        if(i<n){
            if((arr[ind]*2)<=arr[i]){
                solve(arr,n,k,i,count+1);
                solve(arr,n,k,i,count);
                flag=1;
            }
        }
    }
    if(flag==0){
        solve(arr,n,k,ind+1,count);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr,n,k,0,0);
    cout<<max_count+1;
    
    return 0;
}