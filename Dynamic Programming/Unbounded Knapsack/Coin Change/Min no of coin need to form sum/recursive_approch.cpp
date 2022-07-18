#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int target=INT_MAX;
void checkSum(vector<int>coin,vector<int>subset,int n,int i,int sum,int no_of_element){
    if(sum==0){
        target=min(target,no_of_element);        
    }
    if(i==n || sum<0){
        return ;
    }
    subset.push_back(coin[i]);
    checkSum(coin,subset,n,i,sum-coin[i],no_of_element+1);
    subset.pop_back();
    checkSum(coin,subset,n,i+1,sum,no_of_element);
    
}
int main(){
    vector<int>coin={3,4,5};
    int n=coin.size();
    int sum=5;
    vector<int>subset={};
    checkSum(coin,subset,n,0,sum,0);
    cout<<target<<endl;
    return 0;
}