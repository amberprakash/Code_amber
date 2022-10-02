#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>&pages,int k,int mid){
    int student=1;
    int sum=0;
    int N=pages.size();
    for(int i=0;i<N;i++){
        if(pages[i]>mid){
            return false;
        }
        if(sum+pages[i]>mid){
            student++;
            sum=pages[i];
            if(student>k){
                return false;
            }
        }else{
            sum+=pages[i];
        }
    }
    return true;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>pages(n);
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    int sum=0;
    for(auto x:pages){
        sum+=x;
    }
    int l=0;
    int h=sum;
    int ans=-1;
    while(l<=h){
        int mid= l +(h-l)/2;
        if(isValid(pages,k,mid)==true){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}