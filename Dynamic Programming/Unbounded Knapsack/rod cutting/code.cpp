#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>length={1,2,3,4,5,6,7,8};//size of this work as 'n' in Knapsack or unbounded knapsack 
    vector<int>price={1,5,8,9,10,17,17,20};
    int N=8;//Work as W in knapsack and unbounded Knapsack
    int m=length.size();
    int t[m+1][N+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<N+1;j++){
             if(i==0 || j==0){
                 t[i][j]=0;
             }
        }
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<N+1;j++){
            if(length[i-1]<=j){
                 t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    cout<<t[m][N]<<endl;
    return 0;
}