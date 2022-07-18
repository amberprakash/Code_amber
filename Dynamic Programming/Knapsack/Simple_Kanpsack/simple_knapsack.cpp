// Simple Knapsack recursive approch 
// #include<iostream>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int>val,vector<int>wt,int weight,int n){
    if(n==0 || weight==0){
        return 0;
    }
    if(wt[n-1]<=weight){
        return std::max((val[n-1]+knapsack(val,wt,weight-wt[n-1],n-1)),knapsack(val,wt,weight,n-1));
    }
    
        return knapsack(val,wt,weight,n-1);
    
}
int main(){
    vector<int>val={10,40,30,50};
    vector<int>wt={5,4,6,3};
    int weight=10;
    int maxprofit;
    maxprofit=knapsack(val,wt,weight,val.size());
    cout<<maxprofit<<endl;
    return 0;
}