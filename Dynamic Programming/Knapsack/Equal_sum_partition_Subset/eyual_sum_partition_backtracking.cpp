#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int target=0;
void subset_sum(vector<int>arr,vector<int>subset,int i,int n,int sum,int tillsum){
    if(i>=n){
        return;
    }
    if(tillsum==sum){
        target=1;
        return;
    }
    tillsum+=arr[i];
    subset.push_back(arr[i]);
    subset_sum(arr,subset,i+1,n,sum,tillsum);
    tillsum-=arr[i];
    subset.pop_back();
    subset_sum(arr,subset,i+1,n,sum,tillsum);
}
int main(){
    vector<int>arr={1,5,11,5};
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0){
        cout<<"FALSE"<<endl;
    }
    else{
        sum=sum/2;
        vector<int>subset={};
        subset_sum(arr,subset,0,n,sum,0);
        if(target==0){
            cout<<"FALSE"<<endl;
        }
        else{
            cout<<"TRUE"<<endl;
        }
    }
    return 0;
}