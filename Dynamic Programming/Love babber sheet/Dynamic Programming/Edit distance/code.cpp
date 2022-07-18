#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// techdose solution
int main(){
    string x,y;
    cin>>x;
    cin>>y;
    int n=x.length();
    int m=y.length();
    int t[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0){
                t[i][j]=j;
            }
            if(j==0){
                t[i][j]=i;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=t[i-1][j-1];
            }
            else{
                t[i][j]=1+min(min(t[i][j-1], //INSERT
                              t[i-1][j]), // Remove
                              t[i-1][j-1]); // REPLACE
            }
        }
    }
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<m+1;j++){
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<endl;
    cout<<t[n][m];
    return 0;
}