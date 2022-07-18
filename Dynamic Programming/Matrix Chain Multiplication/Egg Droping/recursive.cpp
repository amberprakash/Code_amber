#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//as we have to find tha gauranteed min no of attempts to find floor from which it will not break.....So we always consider worst case in (min)  and best case in (max)
int solve(int e,int f){
   if(e==1){
       return f;
   }
   if(f==0 || f==1){
       return f;
   }
   int mn=INT_MAX;

   for(int k=1;k<=f;k++){
        int temp=1+max(solve(e-1,k-1),solve(e,f-k));
        mn=min(mn,temp);
   }
   return mn;
}
int main(){
    int e,f;
    cin>>e>>f;
    int temp=solve(e,f);
    cout<<temp<<endl;
    return 0;
}