#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>num(n);
    vector<int>rep(m);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<m;i++){
        cin>>rep[i];
    }
    if(n==0){
        cout<<"NULL";
    }
    else if(m==0){
        for(auto x:num){
            cout<<x<<" ";
        }
    }else{
        priority_queue<int>pq(rep.begin(),rep.end());
        for(int i=0;i<n;i++){
            if(num[i]<pq.top()){
                num[i]=pq.top();
                pq.pop();
            }
        }
        for(auto x:num){
            cout<<x<<" ";
        }
    }
    return 0;
}