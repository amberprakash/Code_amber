#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool cmp(auto &a,auto &b){
    return a+b > b+a;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<string>vec;
    for(auto x:arr){
        vec.push_back(to_string(x));
    }
    sort(vec.begin(),vec.end(),[&](string a,string b){

     return a+b > b+a;

    });
    for(auto x:vec){
        cout<<x<<" ";
    }
    return 0;
}