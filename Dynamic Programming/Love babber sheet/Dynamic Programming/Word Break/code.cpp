#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool solve(string A,vector<string>&B){
        int n=A.length();
        vector<int>t(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                string temp=A.substr(j,i-j+1);
                // cout<<temp<<" ";
                if(find(B.begin(),B.end(),temp)!=B.end()){
                    if(j>0){
                        t[i]+=t[j-1];
                    }
                    else{
                        t[i]+=1;
                    }
                }
            }
            cout<<t[i]<<" ";
        }
        if(t[n-1]>0){
            return 1;
        }
        return 0;
    }

int main(){
    int n;
    cin>>n;
    vector<string>dict;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        dict.push_back(s);
    }
    string t;
    cin>>t;
    cout<<endl<<solve(t,dict)<<endl;
    return 0;
}