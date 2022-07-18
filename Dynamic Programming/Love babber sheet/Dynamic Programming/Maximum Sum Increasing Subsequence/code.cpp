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
    vector<int>prefix(n);
    prefix[0]=arr[0];
    int ans=prefix[0];
    
    for(int i=1;i<n;i++){
        int mix=0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                if(prefix[i]>mix){
                    mix=prefix[j];
                }
            }
        }
        if(mix==0){
            prefix[i]=arr[i];
        }
        else{
            prefix[i]=mix+arr[i];
            ans=max(ans,prefix[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}