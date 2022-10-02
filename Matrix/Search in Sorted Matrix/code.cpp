#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,target;
    cin>>n>>m>>target;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    if(target<mat[0][0] || target>mat[n-1][m-1]){
        cout<<"False";
    }else{
        int i=0;
        int j=m-1;
        int flag=0;
        while(i<n &&j>=0){
            if(target==mat[i][j]){
                cout<<"TRUE";
                flag=1;
                break;
            }else if(mat[i][j]>target){
                j--;
            }else{
                i++;
            }
        }
        if(flag==0){
            cout<<"False";
        }
    }
    return 0;
}