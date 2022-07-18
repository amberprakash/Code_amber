#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//top-down approch
int main(){
    vector<int>arr={2,3,5,6,8,10};
    int n=arr.size();
    int sum=10;
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
                t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<t[n][sum]<<endl;
    return 0;
}