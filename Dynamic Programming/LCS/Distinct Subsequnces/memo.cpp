#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int numDistinctUtil(vector<vector<int>> &memo, int i, int j, const string A, const string B) {
  
  if(memo[i][j] != -1) {
    return memo[i][j];
  }
  // B has no more characters left, so solution will be 1
  if(j == 0) { memo[i][j] = 1; }
  // If A has no more characters left but B still has characters,
  // solution will be 0
  else if(i == 0) { memo[i][j] = 0; }
    
  else {
    // Solution getting from previous state, i.e. 
    // ignoring current   character of A
    
    int soln1 = numDistinctUtil(memo, i - 1, j, A, B);
    int soln2 = 0;
    
    // Case when characters are same
    if(A[i-1] == B[j-1]) { soln2 = numDistinctUtil(memo, i-1, j-1, A, B); }
    
    memo[i][j] = soln1 + soln2;
  }
  return memo[i][j];
}
int main(){
    
    return 0;
}