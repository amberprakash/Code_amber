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
    sort(arr.begin(),arr.end());
    int missing=1;
    for(int i=0;i<n;i++){
        if(arr[i]==missing){
            missing++;
        }else{
            if(arr[i]>0){
                break;
            }
        }
    }
    cout<<missing;
    return 0;
}