#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr,int i,int j){
    if(i>=j){
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(temp<mn){
            mn=temp;
        }
    }
    return mn;
}
int main(){
    vector<int>arr={40,20,30,10,30};
    int n=arr.size();
    int ans=solve(arr,1,n-1);
    cout<<ans<<endl;
    return 0;
}