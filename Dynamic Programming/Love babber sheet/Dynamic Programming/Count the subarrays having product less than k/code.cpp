#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=0;
        long long prod=1;
        int i=0,j=0;
        
        for(i=0;i<n;i++){
            prod*=a[i];
            if(prod>k){
                while(prod>=k && j<=i){
                    prod/=a[j];
                    ++j;
                }
            }
            if(prod<k){
                ans+=i-j+1;
            }
        }
        return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int k;
    cin>>k;
    cout<<countSubArrayProductLessThanK(arr,n,k)<<endl;
    return 0;
}