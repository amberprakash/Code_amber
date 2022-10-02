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
    stack<int>st;
    vector<int>ans(n,-1);
    st.push(0);
    for(int i=1;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            ans[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}