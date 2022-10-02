#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (arr[0] < arr[n - 1])
    {
        cout << arr[0];
    }
    else
    {
        int ans = -1;
        int l = 0;
        int h = n - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (arr[mid] > arr[mid + 1])
            {
                ans = arr[mid + 1];
                break;
            }
            if (arr[mid - 1] > arr[mid])
            {
                ans = arr[mid];
                break;
            }
            if (arr[mid] > arr[h])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        cout << ans;
    }
    return 0;
}