#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>smallest(10,0);
    for(int i=0;i<n;i++){
        smallest[s[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        if(smallest[i]==0){
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}