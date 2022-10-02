#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int first(vector<int> &arr, int n, int x)
{
    int ans = -1;
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int mid = (l + (h - l) / 2);
        if (arr[mid] == x)
        {
            ans = mid;
            h = mid - 1;
        }
        else if (arr[mid] > x)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
int second(vector<int> &arr, int n, int x)
{
    int ans = -1;
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int mid = (l + (h - l) / 2);
        if (arr[mid] == x)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (arr[mid] > x)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int a = first(arr, n, x);
    int b = second(arr, n, x);
    cout<<a<<" "<<b;
    return 0;
}