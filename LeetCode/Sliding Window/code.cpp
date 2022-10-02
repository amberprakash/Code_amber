#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s;
    cin>>t;
    if(s.size()<t.size()){
        cout<<"NULL";
    }else{
        unordered_map<char,int>mpt;
        int freqt=0;
        for(auto x:t){
            mpt[x]++;
            freqt++;
        }
        int start,L=0,R=0;
        int ans=INT_MAX;
        unordered_map<char,int>mps;
        int freqs=0;
        while(R<s.size()){
            mps[s[R]]++;
            if(mps[s[R]]<=mpt[s[R]]){
                freqs++;
            }
            if(freqs==freqt){
                while(freqs==freqt){
                    mps[s[L]]--;
                    if(R-L+1<ans){
                        ans=R-L+1;
                        start=L;
                    }
                    if(mps[s[L]]<mpt[s[L]]){
                        freqs--;
                    }
                    L++;
                }

            }
            R++;
        }
        ans==INT_MAX?cout<<"NULL":cout<<s.substr(start,ans);
    }
    return 0;
}