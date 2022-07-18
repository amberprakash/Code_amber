#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void solve(vector<int>&A,int B,int i,vector<int>&temp){
        if(B==0){
            ans.push_back(temp);
            return;
        }
        if(B<0){
            return;
        }
        for(int k=i;k<A.size();k++){
            if(k>0 && A[k]==A[k-1]){
                continue;
            }
            temp.push_back(A[k]);
            solve(A,B-A[k],k,temp);
            temp.pop_back();
        }
    }
int main(){
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int>temp;
    solve(arr,target,0,temp);
    for(int i=0;i<ans.size();i++){
        cout<<"(";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<")";
        cout<<endl;
    }
    return 0;
}