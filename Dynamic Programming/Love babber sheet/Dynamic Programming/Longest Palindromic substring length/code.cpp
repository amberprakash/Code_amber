#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string x,y;
    cin>>x;
    y=x;
    reverse(y.begin(),y.end());
    int n=x.length();
    int t[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 ||j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=(1+t[i-1][j-1]);
            }
            else{
                t[i][j]=0;
            }
        }
    }
    int mx=INT_MIN;
    int a,b;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(t[i][j]>mx){
                mx=t[i][j];
                a=i;
                b=j;
            }
        }
    }
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<n+1;j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<mx<<endl;
    string f="";
    while(mx>0){
        f.push_back(x[a-1]);
        a--;
        mx--;
    }
    cout<<f;
    
    return 0;
}