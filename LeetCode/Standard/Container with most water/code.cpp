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
    int ans=INT_MIN;
    int i=0;
    int j=n-1;
    while(i<j){
        int area=(j-i)*min(height[i],height[j]);
        if(height[i]<height[j]){
            i++;
        }else{
            j--;
        }
        ans=max(ans,area);
    }
    cout<<ans;
    return 0;
}