#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// Given an array A containing N integers.

// You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

// If no such triplet exist return 0.

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> right(n); // contain rightest greatest element
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    set<int> left;
    left.insert(arr[0]);
    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        auto l = left.lower_bound(arr[i]);
        l--;
        if (l != left.end() && right[i + 1] > arr[i] && arr[i] > *l)
        {
            ans = max(ans, *l + arr[i] + right[i + 1]);
        }
        left.insert(arr[i]);
    }
    cout << ans;
    return 0;
}