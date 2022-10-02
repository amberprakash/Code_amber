#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int>&sticks,int ind,int k,int subsetSum,int currSum,int n,vector<int>&visited){
    if(k==4){
        return true;
    }
    if(currSum==subsetSum){
        return possible(sticks,0,k+1,subsetSum,0,n,visited);
    }
    for(int i=ind;i<n;i++){
        if(currSum+sticks[i]>subsetSum || visited[i]==1){
            continue;
        }
        currSum+=sticks[i];
        visited[i]=1;
        if(possible(sticks,i+1,k,subsetSum,currSum,n,visited)){
            return true;
        }
        currSum-=sticks[i];
        visited[i]=0;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int>sticks(n);
    for(int i=0;i<n;i++){
        cin>>sticks[i];
    }
    int sum=0;
    for(auto x:sticks){
        sum+=x;
    }
    if(sum%4!=0){
        cout<<"FALSE";
    }else{
        sum=sum/4;
        vector<int>visited(n,0);
        if(possible(sticks,0,0,sum,0,n,visited)){
            cout<<"TRUE";
        }else{
            cout<<"FALSE";
        }
    }

    return 0;
}