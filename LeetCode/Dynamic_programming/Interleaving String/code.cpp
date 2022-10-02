#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool solve(string s1,string s2,string s3,int x,int y,int z,int n,int m,int p){
    if(z==p){
        if(x==n && y==m){
            return true;
        }else{
            return false;
        }
    }
    if(x==n){
        if(s2[y]==s3[z]){
            return solve(s1,s2,s3,x,y+1,z+1,n,m,p);
        }else{
            return false;
        }
    }else if(y==m){
        if(s1[x]==s3[z]){
            return solve(s1,s2,s3,x+1,y,z+1,n,m,p);
        }else{
            return false;
        }
    }
    bool right=false,left=false;
    if(s3[z]==s1[x]){
        right=solve(s1,s2,s3,x+1,y,z+1,n,m,p);
    }
    if(s3[z]==s2[y]){
        left=solve(s1,s2,s3,x,y+1,z+1,n,m,p);
    }
    return (right || left);
}

int main(){
    string s1,s2,s3;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    int n=s1.length();
    int m=s2.length();
    int p=s3.length();
    if(solve(s1,s2,s3,0,0,0,n,m,p)){
        cout<<"TRUE";
    }else{
        cout<<"FALSE";
    }
    return 0;
}