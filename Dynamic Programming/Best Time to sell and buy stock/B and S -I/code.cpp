#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int minC=INT_MAX;
    int profit=INT_MIN;
    for(int i=0;i<n;i++){
        minC=min(minC,prices[i]);
        profit=max(profit,prices[i]-minC);
    }
    cout<<profit;
    return 0;
}