#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int ans=-1;
    int i=0;
    int j=m-1;
    while(i>=0 && j>=0 && i<n && j<m){
        if(mat[i][j]==x){
            ans=1;
            break;
        }else if(mat[i][j]>x){
            j--;
        }else{
            i++;
        }
    }
    cout<<ans;
    return 0;
}