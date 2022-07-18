#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>paths;
void solve(vector<vector<int>>&t,vector<int>&temp,int i,int j,int n,int m){
    if(i>n || i<0 || j>m || j<0 ){
        return ;
    } 
    if(i==n && j==m){
        temp.push_back(t[i][j]);
      paths.push_back(temp);
      temp.pop_back();
      return;
    }
    temp.push_back(t[i][j]);
    solve(t,temp,i+1,j,n,m);
    solve(t,temp,i,j+1,n,m);
    temp.pop_back();

}

int main(){
    int n,m,h;
    cin>>n>>m>>h;
    vector<vector<int>>t(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>t[i][j];
        }
    }
    vector<int>temp={};
    solve(t,temp,1,1,n,m);
    // for(int i=0;i<paths.size();i++){
    //     for(int j=0;j<paths[i].size();j++){
    //         cout<<paths[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int count=0;
    int flag=0;
   
    for(int i=0;i<paths.size();i++){
        vector<int>pet=paths[i];
        
        int k=pet.size();
        cout<<k<<" ";
        for(int j=1;j<=k;j++){
            if((pet[j]+pet[k-(j+1)])%h!=0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            count++;
        }
        flag=0;
      
    }
    // cout<<count;

    return 0;
}