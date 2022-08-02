#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
void solve(string s,int open,int close){
    if(open==0 && close==0){
        ans.push_back(s);
        return;
    }
    if(open>0){
        solve(s+"(",open-1,close);
    }
    if(close>open){
        solve(s+")",open,close-1);
    }
}
int main(){
    int n;
    cin>>n;
    solve("",n,n);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}