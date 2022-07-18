#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> mat, int n)
{
    int t[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                t[i][j] = mat[i][j];
            }
            else
            {
                if (j == 0)
                {
                    t[i][j] = mat[i][j] + max(t[i - 1][j], t[i - 1][j + 1]);
                }
                else if (j == n - 1)
                {
                    t[i][j] = t[i][j]+max(t[i - 1][j], t[i - 1][j - 1]);
                }
                else
                {
                    t[i][j] = t[i][j]+ max(max(t[i - 1][j], t[i - 1][j - 1]), t[i - 1][j + 1]);
                }
            }
        }
    }
    int mx=0;
    for(int i=0;i<n;i++){
         mx=max(mx,t[n-1][i]);
    }
    return mx;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout<<solve(mat,n);
    return 0;
}