#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<vector<string>>ans;
bool isPalindrome(string s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve(int i,string s,vector<string>&temp){
    if(i==s.length()){
        ans.push_back(temp);
        return;
    }
    for(int k=i;k<s.length();k++){
        if(isPalindrome(s,i,k)){
            temp.push_back(s.substr(i,k-i+1));
            solve(k+1,s,temp);
            temp.pop_back();
        }
    }
}
int main(){
    string s;
    cin>>s;
    vector<string>temp;
    solve(0,s,temp);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}