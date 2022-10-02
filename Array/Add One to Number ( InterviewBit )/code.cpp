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
    int carry=1;
    for(int i=n-1;i>0;i--){
        if(arr[i]+carry==10){
            arr[i]=0;
            carry=1;
        }else{
            arr[i]=arr[i]+carry;
            carry=0;
        }
    }
    if(arr[0]+carry==10){
        arr[0]=0;
        arr.insert(arr.begin(),1);
    }else{
        arr[0]=arr[0]+carry;
        while(arr[0]==0){
            arr.erase(arr.begin());
        }
    }
    for(auto x:arr){
        cout<<x;
    }

    return 0;
}