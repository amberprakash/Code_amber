#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> lcs(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int mx = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(arr[i] - arr[j]) == 1)
            {
                lcs[i] = max(lcs[i], lcs[j] + 1);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, lcs[i]);
    }
    cout << mx << endl;
    for (auto &i : lcs)
    {
        cout << i << " ";
    }
    return 0;
}