#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> val = {10, 40, 30, 50};
    vector<int> wt = {5, 4, 6, 3};
    int weight = 10;
    int n = val.size();
    int t[n + 1][weight + 1];
    int maxprofit;
    // initialization of first row and first column
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < weight + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    // filling up of rest row and column
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < weight + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = std::max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    cout<<t[n][weight]<<endl;

    return 0;
}