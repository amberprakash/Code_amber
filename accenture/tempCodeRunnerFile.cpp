#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int res;
void solve(vector<int>arr,int n,int ind,int m,int leftind){
    if(ind>leftind || ind>n-2){
        return;
    }
    if(m==0){
        
       for(int i=1;i<leftind;i++){
           if(arr[i]<=arr[i-1]){
               return;
           }
       }
       res=1;
       return;
    }
    solve(arr,n,ind+1,m,leftind);
    int var=0;
    var=arr[ind]+arr[ind+1]+arr[ind+2];
    arr[ind]=var;
    int f=ind+1;
    int fgx=ind+3;
    if(fgx<leftind){
       while(fgx<leftind){
           arr[f]=arr[fgx];
           f++;
           fgx++;
       }
    }
    solve(arr,n,ind+1,m-1,leftind-2);
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n;
        cin>>m;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
             cin>>arr[i];
        }
        res=0;
        solve(arr,n,0,m,n);
        cout<<res<<endl;

    }
    return 0;
}