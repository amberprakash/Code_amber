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
    int up=1;
    int down=1;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            up=down+1;
        }else{
            down=up+1;
        }
    }
    cout<<max(up,down);
    return 0;
}