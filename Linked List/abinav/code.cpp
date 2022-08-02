#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string first_name,last_name,PIN;
    int N;
    cin>>first_name;
    cin>>last_name;
    cin>>PIN;
    cin>>N;
    string small,large;
    if(first_name.length()>last_name.length()){
        large=first_name;
        small=last_name;
    }else{
        large=last_name;
        small=first_name;
    }
    if(first_name.length()==last_name.length()){
        if(first_name>last_name){
            small=last_name;
            large=first_name;
        }else{
            large=last_name;
            small=first_name;
        }
    }
    // cout<<small;
    string user_id="";
    int n=small.length();
    int m=large.length();
    // cout<<small[n-1];
    user_id+=small[n-1];
    // user_id.append(to_string(small[n-1]));
    // cout<<user_id;
    // cout<<user_id<<endl;
    user_id.append(large);
    // cout<<user_id<<endl;
    // user_id.append(to_string(PIN[N-1]));
    user_id+=PIN[N-1];
    int x=PIN.length();
    // user_id.append(to_string(PIN[x-N]));
    user_id+=PIN[x-N];
    cout<<user_id<<endl;
    for(auto &x:user_id){
        if(x>=97 && x<=122){
            x=toupper(x);
        }else if(x>=65 && x<=90){
            x=tolower(x);
        }
    }
    cout<<user_id;
    return 0;
}