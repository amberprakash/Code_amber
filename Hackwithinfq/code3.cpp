#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solve(int N,vector<int>A){
     int i=0;
    int j=1;
    int count=0;
    while(j<N){
        if(A[i]>=A[j]){
            count++;
            j++;
        }
        else{
            i=j;
            j=i+1;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<solve(n,arr);
    return 0;
}