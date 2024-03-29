#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={1,6,5,11};
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        t[i][0]=true;
    }
    for(int j=1;j<sum+1;j++){
        t[0][j]=false;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    vector<int>store;
    for(int i=0;i<=sum/2;i++){
        if(t[n][i]==1){
            store.push_back(i);
        }
    }
    int mn=INT_MAX;
    for(int i=0;i<store.size();i++){
        mn=min(mn,sum-2*store[i]);
    }
    
    cout<<mn<<endl;
    return 0;
}
