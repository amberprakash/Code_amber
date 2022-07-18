#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int t[10002];
int solve(int n,int x,int y,int z){
    if(n==0){
        return 0;
    }
    if(t[n]!=-1){
        return t[n];
    }
    int a=INT_MIN,b=INT_MIN,c=INT_MIN;
    if(x<=n){
        a=solve(n-x,x,y,z);
    }
    if(y<=n){
        b=solve(n-y,x,y,z);
    }
    if(z<=n){
        c=solve(n-z,x,y,z);
    }
    int temp=max(a,max(b,c))+1;
    return t[n]=temp;
}
int main(){
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    memset(t,-1,sizeof(t));
    int ans=solve(n,x,y,z);
    cout<<ans;
    return 0;
}