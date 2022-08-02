#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
void solve(string s,int x,int y){
    ans.push_back(s);
    if(x==0 && y==0){
        return;
    }
    if(x>0){
        solve(s+"X",x-1,y);
    }
    if(y>x){
        solve(s+"Y",x,y-1);
    }
    return;
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