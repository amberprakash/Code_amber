#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int mind = INT_MAX;
string s = "";
vector<int> anst1;
vector<int> anst2;
void solve(vector<int> &arr, int i, vector<int> &subset1, vector<int> &subset2, int sum1, int sum2)
{
    if (i == arr.size())
    {
        int temp = abs(sum1 - sum2);
        if (temp < mind)
        {
            mind = temp;
            anst1 = subset1;
            anst2 = subset2;
            return;
        }
    }
    if (subset1.size() < (arr.size() + 1) / 2)
    {
        subset1.push_back(arr[i]);
        solve(arr, i + 1, subset1, subset2, sum1 + arr[i], sum2);
        subset1.pop_back();
    }
    if (subset2.size() < (arr.size() + 1) / 2)
    {
        subset2.push_back(arr[i]);
        solve(arr, i + 1, subset1, subset2, sum1, sum2 + arr[i]);
        subset2.pop_back();
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
    vector<int> subset1;
    vector<int> subset2;
    solve(arr, 0, subset1, subset2, 0, 0);
    for (auto &x : anst1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto &x : anst2)
    {
        cout << x << " ";
    }
    return 0;
}