#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//return the number of elements smaller than or equal to x
int countLessOrEqual(int x,vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();
    int r=0,c=n-1,count=0;
    for(r=0;r<n;r++){
        while(c>=0 && mat[r][c]>x){
            c--;
        }
        count+=c+1;
    }
    return count;
}


int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    int ans=-1;
    int left=mat[0][0];
    int right=mat[n-1][m-1];
    while(left<=right){
        int mid=(left+right)/2;
        if(countLessOrEqual(mid,mat)>=k){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    cout<<ans;
    return 0;
}