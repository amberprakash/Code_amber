

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
    int k;
    cin>>k;
    int t[k+1][n+1];
    memset(t,0,sizeof(t));
    for(int i=1;i<k+1;i++){
        for(int j=1;j<n+1;j++){
            t[i][j]=t[i][j-1]; // previous subsequnces whwn no is not included
            if(arr[j-1]<=i && arr[j-1]>0){
                t[i][j]+=t[i/arr[j-1]][j-1]+1;//when element is smaller or equal to {i} then we do i/arr[j-1] = x , if multiply arr[j-1] with no greater than x then product will exceed {i} + we add 1 for  {arr[j-1]}
            }
        }
    }
    cout<<t[k][n];
    return 0;
}