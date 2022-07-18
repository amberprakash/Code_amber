#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int numDistinctUtil(string S, string T, int i, int j) { 
  if (i < 0 || j < 0 || i < j) 
    return 0; 
 
  if (S[i]==T[j]) { 
    if (j == 0) 
      return numDistinctUtil(S, T, i-1, j) + 1; 
    else {
      return numDistinctUtil(S, T, i-1, j) + numDistinctUtil(S, T, i-1, j-1);
    }      
  } 
  return numDistinctUtil(S, T, i-1, j); 
}
int main(){
    string X,Y;
    cin>>X>>Y;
    int n=X.length();
    int m=Y.length();
    vector<vector<int>>memo(n+1,vector<int>(m+1,-1));
    cout<<numDistinctUtil(X,Y,n-1,m-1);
    return 0;
}