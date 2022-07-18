#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//Top-Down code of Subset Sum problem
int main(){
    vector<int>arr={2,2,3};
    int sum=5;
    int n=arr.size();
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
    cout<<t[n][sum]<<endl;
    return 0;
}