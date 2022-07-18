#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//Dynamic Programming code 
//Time complexity O(n^2)
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>LCS(n);
    int ans=0;
    LCS[0]=1;
    for(int i=1;i<LCS.size();i++){
        int mat=0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                if(LCS[j]>mat){
                    mat=LCS[j];
                }
            }
        }
        LCS[i]=mat+1;
        if(LCS[i]>ans){
            ans=LCS[i];
        }
    }
    // cout<<ans<<endl;
    // for(auto &i:LCS){
    //     cout<<i<<" ";
    // }
    return 0;
}