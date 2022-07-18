#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];

int LCS(string X,string Y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(t[n][m]!=-1){
        return t[n][m];
    }
    if(X[n-1]==Y[m-1]){
         return t[n][m]=(1+ LCS(X,Y,n-1,m-1));
    }
    else{
        return t[n][m]=max(LCS(X,Y,n,m-1),LCS(X,Y,n-1,m));
    }
    
}

int main(){
    string X,Y;
    cin>>X;
    cin>>Y;
    int n=X.length();
    int m=Y.length();
    memset(t,-1,sizeof(t));
    cout<<LCS(X,Y,n,m)<<endl;
    return 0;
}