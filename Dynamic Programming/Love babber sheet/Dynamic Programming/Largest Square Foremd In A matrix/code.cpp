#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
 int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int t[n][m];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    t[i][j]=mat[i][j];
                }
                else if(i==n-1){
                    t[i][j]=mat[i][j];
                }
                else if(j==m-1){
                    t[i][j]=mat[i][j];
                }
                else{
                    if(mat[i][j]==0){
                        t[i][j]=0;
                    }
                    else{
                        t[i][j]=min(min(t[i+1][j],t[i][j+1]),t[i+1][j+1])+1;
                    }
                }
            }
        }
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,t[i][j]);
            }
        }
        return ans;
    }
int main(){
    
    return 0;
}