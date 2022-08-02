#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    int leftsmall[n],rightsmall[n];
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && height[st.top()]>=height[i]){
            st.pop();
        }
        if(st.empty()){
            leftsmall[i]=0;
        }else{
            leftsmall[i]=st.top()+1;
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && height[st.top()]>=height[i]){
            st.pop();
        }
        if(st.empty()){
            rightsmall[i]=n-1;
        }
        else{
            rightsmall[i]=st.top()-1;
        }
        st.push(i);
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,(rightsmall[i]-leftsmall[i]+1)*height[i]);
    }
    cout<<ans;
    return 0;
}