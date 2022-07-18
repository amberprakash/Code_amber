#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int isPalindrome(string s,int i,int j){
    if(i==j){
        return true;
    }
    if(i>j){
        return true;
    }
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string s,int i,int j){
    if(i>=j){
        return 0;
    }
    if(isPalindrome(s,i,j)==true){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int left,right;
        if(t[i][k]!=-1){
            left=t[i][k];
        }
        else{
            left=solve(s,i,k);
        }
        if(t[k+1][j]!=-1){
            right=t[k+1][j];
        }
        else{
            right=solve(s,k+1,j);
        }

        int temp= left+right+1;
        ans=min(ans,temp);
    }
    return t[i][j]=ans;
}
int main(){
    string s;
    cin>>s;
    memset(t,-1,sizeof(t));
    int n=s.length();
    cout<<solve(s,0,n-1);
    return 0;
}