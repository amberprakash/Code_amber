#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
long long countWays(int n, int k){
        // code here
        int mod=1e9+7;
        if(n==1){
            return k;
        }
        if(n==0){
            return 0;
        }
        long long same=k*1;
        long long diff=k*(k-1);
        long long total=same+diff;
        if(n==2){
            return total;
        }
        for(int i=3;i<=n;i++){
            same=(diff*1)%mod;
            diff=(total*(k-1))%mod;
            total=(same+diff)%mod;
        }
        return total%mod;
    }
int main(){
    
    return 0;
}