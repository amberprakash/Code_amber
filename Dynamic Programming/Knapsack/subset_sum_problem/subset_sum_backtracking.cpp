#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int target=0;
void sum_check(vector<int>arr,vector<int>subset,int i,int n,int sum,int tillsum){
   if(tillsum==sum){
       target=1;
       return ;
   }
   if(i>=n){
       return ;
   }
   tillsum+=arr[i];
   subset.push_back(arr[i]);
   sum_check(arr,subset,i+1,n,sum,tillsum);
   subset.pop_back();
   tillsum-=arr[i];
   sum_check(arr,subset,i+1,n,sum,tillsum);
   
}
int main(){
    vector<int>arr={2,2,3};
    int n=arr.size();
    int sum=7;
    vector<int>subset={};
    sum_check(arr,subset,0,n,sum,0);
    if(target==1){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
   
    return 0;
}