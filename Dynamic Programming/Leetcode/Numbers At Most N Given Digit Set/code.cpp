#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{   int digitsSize;
    cin>>digitsSize;
    vector<string>digits(digitsSize);
    for(int i=0;i<digitsSize;i++){
        cin>>digits[i];
    }
    int n;
    cin>>n;
    string x=to_string(n);
    int k=x.length();
    vector<int>dp(k+1);
    dp[k]=1;
    int ans=0;
    // calculating total numbers of length 'k' which are smaller than 'n'.
    // calulate from last or right side of number
    for(int i=k-1;i>=0;i--){
        int t=x[i]-'0';
        for(string &d:digits){
            if(stoi(d)<t){
                dp[i]+=pow(digitsSize,k-i-1);
            }
            else if(stoi(d)==t){
                dp[i]+=dp[i+1];
            }
        }
    }
    // for calculation numbers length smaller than k
    for(int i=1;i<k;i++){
        dp[0]+=pow(digitsSize,i);
    }
    cout<<dp[0];
    return 0;
}