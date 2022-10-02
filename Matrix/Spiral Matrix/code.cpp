#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<int>ans;
    int top=0;
    int bottom=n-1;
    int left=0;
    int right=m-1;

    while(top<=bottom && left<=right){

        for(int i=left;i<=right;i++){
            ans.push_back(mat[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(mat[i][right]);
        }
        right--;
        if(!(top>bottom)){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            
        }
        bottom--;
        if(!(left>right)){
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
        }
        left++;
    }
    for(auto x:ans){
        cout<<x<<" ";
    }

    return 0;
}