#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define temp 32
#define m 1000000007
#define ll long long
ll power(ll x,ll y,ll p){
  ll res=1;
  x=x%p;
  if(x==0){
    return 0;
  }
  while(y>0){
    if(y&1){
      res=(res*x)%p;
    }
    y=y>>1;
    x=(x*x)%p;
  }
  return res;
}
int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    ll ans=0,s;
    for(int i=0;i<32;i++){
      ll countbit=0;
      for(int j=0;j<n;j++){
        if(arr[j] & (1<<i)){
          countbit +=1;
        }
      }
      s=power(2,countbit,m)-1;
      s=(s*power(2,i,m))%m;
      ans=(ans+s)%m;
    }
    
    cout<<ans<<endl;
  }
  
  return 0;
}
