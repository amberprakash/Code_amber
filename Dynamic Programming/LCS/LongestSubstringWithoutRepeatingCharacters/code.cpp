#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<int>ramp(256,-1);
    int start=-1,i=0,maxlength=0;
    for(i=0;i<n;i++){
        if(ramp[s[i]]>start){
            start=ramp[s[i]];
        }
        ramp[s[i]]=i;
        maxlength=max(maxlength,i-start);
    }
    cout<<maxlength;
    return 0;
}