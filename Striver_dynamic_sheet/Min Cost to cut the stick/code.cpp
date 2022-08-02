#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&cuts,int i,int j){
    if(i>j){
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i;k<=j;k++){
        int temp=cuts[j+1]-cuts[i-1] + solve(cuts,i,k-1)+solve(cuts,k+1,j);
        mn=min(mn,temp);
    }
    return mn;
}

int main(){
    int N;
    cin>>N;
    int c;
    cin>>c;
    vector<int>cuts(c);
    for(int i=0;i<c;i++){
        cin>>cuts[i];
    }
    cuts.push_back(N);
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cout<<solve(cuts,1,c);
    return 0;
}