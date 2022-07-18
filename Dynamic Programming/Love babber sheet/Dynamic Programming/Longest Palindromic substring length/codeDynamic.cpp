#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string x;
    cin>>x;
    int n=x.length();
    int t[n+1][n+1];
    memset(t,0,sizeof(t));
    for(int i=0;i<n;i++){
        t[i][i]=1;
    }
    int maxlength=1;
    int start;
    for(int i=0;i<n-1;i++){
        if(x[i]==x[i+1]){
            t[i][i+1]=1;
            maxlength=2;
            start=i;
        }
    }
    //for fixing the length k=3 and more than 3
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i+k-1;
            if(t[i+1][j-1] && x[i]==x[j]){
                t[i][j]=1;
                if(k>maxlength){
                    start=i;
                    maxlength=k;
                }
            }
        }
    }
    for(int i=start;i<=start+maxlength-1;i++){
        cout<<x[i];
    }
    // cout<<endl;
    // cout<<x.substr(start,start+maxlength-1);

    return 0;
}