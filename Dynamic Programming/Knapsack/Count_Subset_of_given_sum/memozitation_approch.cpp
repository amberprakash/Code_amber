#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int target=0;
int t[102][102];
void check_sum(vector<int>arr,int n,int sum){
    if(sum==0){
        target+=1;
        return;
    }
    if(n==0){
       return;
    }
    check_sum(arr,n-1,sum-arr[n-1]);
    check_sum(arr,n-1,sum);
}
int main(){
    memset(t,-1,sizeof(t));
    vector<int>arr={2,3,5,6,8,10};
    int n=arr.size();
    int sum=10;
    check_sum(arr,n,sum);
    cout<<target<<endl;
    return 0;
}