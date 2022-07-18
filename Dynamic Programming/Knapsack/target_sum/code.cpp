#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// Same as count of subset sum difference 
int main(){
    vector<int>arr={1,1,2,3};
    int n=arr.size();
    int sum_given=1;
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=arr[i];
    }
    int sum=(totalsum+sum_given)/2;
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        t[i][0]=1;
    }
    for(int j=1;j<sum+1;j++){
        t[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
             if(arr[i-1]<=j){
                 t[i][j]=(t[i-1][j-arr[i-1]] + t[i-1][j]);
             }
             else{
                 t[i][j]=t[i-1][j];
             }
        }
    }
    cout<<t[n][sum]<<endl;
    return 0;
}