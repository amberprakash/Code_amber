#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int>allsum={};
void subset_sum(vector<int>arr,int n,int i,vector<int>set){
    if(i==n){
         int sum=0;
         for(int i=0;i<set.size();i++){
             sum+=set[i];
         }
         allsum.push_back(sum);
         return ;
    }
    
    set.push_back(arr[i]);
    subset_sum(arr,n,i+1,set);
    set.pop_back();
    subset_sum(arr,n,i+1,set);
}
int main(){
    vector<int>arr={1,6,5,11};
    int n=arr.size();
    vector<int>set={};
    subset_sum(arr,n,0,set);
    sort(allsum.begin(),allsum.end());
    // for(int i=0;i<allsum.size();i++){
    //     cout<<allsum[i]<<" ";
    // }
    int m=allsum.size();
    int t=allsum[m-1];
    vector<int>next;
    for(int i=0;i<allsum.size();i++){
        if(allsum[i]<=t/2){
            next.push_back(allsum[i]);
        }
    }
    int x=next.size();
    cout<<t-2*x<<endl;
    return 0;
}

// not correct answer 
