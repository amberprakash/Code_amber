#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
// using Largest arrea in Histogram code
int maxiArea(vector<int>&height){
    int n=height.size();
    stack<int>st;
    int leftsmall[n],rightsmall[n];
    for(int i=0;i<n;i++){
        while(!st.empty() && height[st.top()]>=height[i]){
            st.pop();
        }
        if(st.empty()){
            leftsmall[i]=0;
        }
        else{
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
        }else{
            rightsmall[i]=st.top()-1;
        }
        st.push(i);
    }
    // for(auto x:rightsmall){
    //     cout<<x<<" ";
    // }
    int area=0;
    for(int i=0;i<n;i++){
        area=max(area,(rightsmall[i]-leftsmall[i]+1)*height[i]);
    }
    return area;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    // vector<int>arr={2,1,5,6,2,3};
    int ans=0;
    vector<int>arr(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1){
                arr[j]++;
            }else{
                arr[j]=0;
            }
        }
        int area=maxiArea(arr);
        ans=max(ans,area);
    }
    cout<<ans;
    return 0;
}