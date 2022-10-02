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
    for(int i=0;i<n/2;i++){
        swap(mat[i],mat[n-i-1]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    cout<<"--------X--------"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}