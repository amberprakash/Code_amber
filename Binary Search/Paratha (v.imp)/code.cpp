#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>&rating,int p,int mid){
    int num=0;
    int n=rating.size();
    for(int i=0;i<n;i++){
        int t=0;
        int next_time=rating[i];
        while(t+next_time<=mid){
            num++;
            t+=next_time;
            next_time+=rating[i];
            if(num>=p){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,p;
    cin>>n>>p;
    vector<int>rating(n);
    for(int i=0;i<n;i++){
        cin>>rating[i];
    }
    sort(rating.begin(),rating.end());
    int l=0;
    int h=rating[n-1]*((p*(p+1))/2);
    int ans=-1;
    while(l<=h){
        int mid = l +(h-l)/2;
        if(isValid(rating,p,mid)==true){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}