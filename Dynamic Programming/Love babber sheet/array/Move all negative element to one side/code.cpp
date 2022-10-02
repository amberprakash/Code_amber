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
    int l=0;
    int h=n-1;
    while(l<h){
        if(arr[l]> 0 && arr[h]<0){
            swap(arr[l],arr[h]);
            l++;
            h--;
        }
        else if(arr[l]<0 && arr[h]>0){
            l++;
            h--;
        }
        else if(arr[l]<0 && arr[h]<0){
            l++;
        }else if(arr[l]>0 && arr[h]>0){
            h--;
        }
    }
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}