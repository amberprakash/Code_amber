#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int t[101][101];
int checkSum(vector<int>coin,int n,int i,int sum,int no_of_element){
    if(sum==0){
        return no_of_element;
    }
    if(i==n || sum<0){
        return INT_MAX;
    }
    return min(checkSum(coin,n,i,sum-coin[i],no_of_element+1),checkSum(coin,n,i+1,sum,no_of_element));
}
int main(){
    vector<int>coin={1,2,3};
    int n=coin.size();
    int sum=5;
    memset(t,-1,sizeof(t));
    int ans=checkSum(coin,n,0,sum,0);
    cout<<ans<<endl;
    return 0;
}