#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// In this we have to find no of ways to find sum equal to given sum
// here unlimited supply of coin is available
// we have choice to select any coin more than one time
// it is problem of unbounded knapsack
int main(){
    vector<int>coin={1,2,3};
    int sum=5;
    int n=coin.size();
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        t[i][0]=1;
    }
    for(int j=1;j<sum+1;j++){
        t[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]<=j){
                t[i][j]=t[i][j-coin[i-1]]+t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<t[n][sum]<<endl;
    return 0;
}