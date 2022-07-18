#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
          cin>>arr[i];
    }
    int minR=INT_MAX;
    int temp=INT_MAX;
    for(int i=0;i<n;i++){
          if(temp>0){
              temp=arr[i];
          }
          else{
              temp+=arr[i];
          }
          minR=min(minR,temp);
    }
    cout<<minR<<endl;
    return 0;
}