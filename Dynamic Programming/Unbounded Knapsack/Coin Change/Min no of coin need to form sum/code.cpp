#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>coin={3,4,5};
    int n=coin.size();
    int sum=5;
    int t[n+1][sum+1];
    for(int i=0;i<sum+1;i++){
        t[0][i]=INT_MAX - 1;
    }
    for(int i=1;i<n+1;i++){
        t[i][0]=0;
    }
    for(int j=1;j<sum+1;j++){
        if(j%coin[0]==0){
            t[1][j]=j/coin[0];
        }
        else{
            t[1][j]=INT_MAX-1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=2;j<sum+1;j++){
            if(coin[i-1]<=j){
                t[i][j]=min(t[i][j-coin[i-1]]+1,t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<t[n][sum]<<endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}