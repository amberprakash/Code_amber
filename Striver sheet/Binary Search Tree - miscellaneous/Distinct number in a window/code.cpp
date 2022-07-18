#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int>solve(vector<int>&arr,int b){
    vector<int>ans;
    int n=arr.size();
    if(b>n){
        return ans;
    }
    map<int,int>m;
    for(int i=0;i<b;i++){
        m[arr[i]]++;
    }
    int t=n-b+1;
    int i=b;
    while(t--){
        ans.push_back(m.size());
        m[arr[i]]++;
        m[arr[i-b]]--;
        if(m[arr[i-b]]==0){
            m.erase(arr[i-b]);
        }
        i++;
    }
    return ans;

}
int main(){
    vector<int>arr={1,2,1,3,4,3};
    int B=3;
    vector<int>temp;
    temp=solve(arr,B);
    for(auto &i:temp){
        cout<<i<<" ";
    }
    return 0;
}