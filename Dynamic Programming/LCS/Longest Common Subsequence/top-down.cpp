#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string X,Y;
    cin>>X;
    cin>>Y;
    int n=X.length();
    int m=Y.length();
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(X[i-1]==Y[j-1]){
                t[i][j]=(1 + t[i-1][j-1]);
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    cout<<t[n][m]<<endl;
    return 0;
}