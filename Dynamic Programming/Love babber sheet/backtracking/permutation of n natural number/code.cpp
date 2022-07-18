#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void solve(vector<int>&temp,int k){
    if(k>temp.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<temp.size();i++){
        if(temp[i]==0){
            temp[i]=k;
            solve(temp,k+1);
            temp[i]=0;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>temp(n,0);
    solve(temp,1);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}