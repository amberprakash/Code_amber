#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//top down approch of equal sum partition
int main(){
    vector<int>arr={1,5,11,5};
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0){
        cout<<"FALSE"<<endl;
    }
    else{
        sum=sum/2;//if even only
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
        if(t[n][sum]==1){
            cout<<"TRUE"<<endl;
        }
        else{
            cout<<"FALSE"<<endl;
        }

    }

    return 0;
}