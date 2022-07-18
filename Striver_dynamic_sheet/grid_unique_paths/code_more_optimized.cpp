#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>cur(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                cur[j]=1;
            }
            else{
                int up=0;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=cur[j-1];
                cur[j]=up+left;
            }
            prev=cur;
        }
        cout<<prev[m-1];
    }
    return 0;
}