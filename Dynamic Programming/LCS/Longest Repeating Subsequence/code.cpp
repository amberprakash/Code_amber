#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string X,Y;
    cin>>X;
    Y=X;
    int n=X.length();
    int t[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if((X[i-1]==Y[j-1]) && i!=j){
                t[i][j]=(1+t[i-1][j-1]);
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;;
    }
    cout<<t[n][n]<<endl;
    return 0;
}