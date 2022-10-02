#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        vector<int>temp(i+1,1);
        for(int j=1;j<i;j++){
            temp[j]=ans[i-1][j]+ans[i-1][j-1];
        }
        ans.push_back(temp);
    }
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
    }
    return 0;
}