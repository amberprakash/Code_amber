#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int findMaxForm(vector<string> &S, int M, int N)
{
    int dp[101][101]{0};
    for (string str : S)
    {
        int zeros = 0, ones = 0;
        for (char c : str)
            c == '0' ? zeros++ : ones++;
        for (int i = M; i >= zeros; i--)
            for (int j = N; j >= ones; j--)
                dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
    }
    for(int i=0;i<M+1;i++){
        for(int j=0;j<N+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[M][N];
}
int main()
{
    vector<string> arr = {"01", "0001", "111001", "1", "0"};
    int n = 5;
    int m = 3;
    cout << findMaxForm(arr, n, m);
    return 0;
}