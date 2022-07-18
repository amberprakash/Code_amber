#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int>arr){
    int ans=INT_MIN;
    int temp=0;
    for(int i=0;i<arr.size();i++){
        temp+=arr[i];
        if(temp>ans){
            ans=temp;
        }
        if(temp<0){
            temp=0;
        }
    }
    return ans;
}


int main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    
    int ans=INT_MIN;
    for(int i=0;i<m;i++){
        vector<int>arr(n,0);
        for(int j=i;j<m;j++){
            for(int k=0;k<n;k++){
                arr[k]+=mat[k][j];
            }
            ans=max(ans,kadane(arr));
        }
    }
    cout<<ans;
    return 0;
}