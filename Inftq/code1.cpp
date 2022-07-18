#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> allsubset;

void solve(vector<int> &arr, vector<int> temp, int n, int i, int prod, int target)
{
    if (prod == target)
    {
        allsubset.push_back(temp);
        return;
    }
    if (prod > target)
    {
        return;
    }

    for (int k = i; k < n; k++)
    {
        // if (i != 0 && arr[i] != arr[i - 1])
        if (i != 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        else
        {

            int temp2 = prod * arr[k];
            temp.push_back(arr[k]);
            solve(arr, temp, n, k, temp2, target);
            temp.pop_back();
        }
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    vector<int> temp = {};
    solve(arr, temp, n, 0, 1, target);
    for (int i = 0; i < allsubset.size(); i++)
    {
        for (int j = 0; j < allsubset[i].size(); j++)
        {
            cout << allsubset[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}