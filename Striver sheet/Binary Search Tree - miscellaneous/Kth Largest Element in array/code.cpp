#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={3,2,1,5,6,4};
    int n=arr.size();
    int k=2;
    nth_element(arr.begin(),arr.begin()+k-1,arr.end(),greater<int>());
    cout<<arr[k-1];
    return 0;
}