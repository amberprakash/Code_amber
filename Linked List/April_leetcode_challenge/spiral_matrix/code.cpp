#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int r1 = 0;
    int r2 = n - 1;
    int c1 = 0;
    int c2 = n - 1;
    int val = 1;
    vector<vector<int>> table(n, vector<int>(n));
    while (r1 <= r2 && c1 <= c2)
    {
        for (int i = c1; i <= c2; i++)
        {
            table[r1][i] = val++;
        }
        for (int i = r1 + 1; i <= r2; i++)
        {
            table[i][c2] = val++;
        }
        if (r1 < r2 && c1 < c2)
        {
            for (int i = c2 - 1; i > c1; i--)
            {
                table[r2][i] = val++;
            }
            for (int i =r2;i>r1;i--){
                table[i][c1]=val++;
            }
        }
        c1++;
        c2--;
        r1++;
        r2--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}