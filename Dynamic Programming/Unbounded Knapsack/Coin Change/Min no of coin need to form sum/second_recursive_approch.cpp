#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
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
    vector<int>coin={1,3,2};
    int n=coin.size();
    int sum=5;
    cout<<checkSum(coin,n,0,sum,0)<<endl;
    return 0;
}