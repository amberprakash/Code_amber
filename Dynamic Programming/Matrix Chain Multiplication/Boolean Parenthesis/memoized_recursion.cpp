#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
int solve(string s,int i,int j,bool flag){
    if(i>j){
        return false;
    }
    if(i==j){
        if(flag==true){
            return s[i]=='T';
        }
        else{
            return s[i]=='F';
        }
    }
    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(flag));
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2){
        int lt=solve(s,i,k-1,true);
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);
        
        if(s[k]=='&'){
            if(flag==true){
                ans=ans+(lt*rt);
            }
            else{
                ans=ans+(lf*rf)+(lf*rt)+(rf*lt);
            }   
        }
        else if(   s[k]=='|'  ){
            if(flag==true){
                ans+=(lt*rt)+(lt*rf)+(lf*rt);
            }
            else{
                ans+=(lf*rf);
            }
        }
        else if(s[k]=='^'){
            if(flag==true){
                ans+=(lt*rf)+(lf*rt);
            }
            else{
                ans+=(rt*lt)+(lf*rf);
            }
        }
        
        
    }
    return mp[temp]=ans;

    
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    mp.clear();
    int temp=solve(s,0,n-1,true);
    cout<<temp<<endl;
    return 0;
}