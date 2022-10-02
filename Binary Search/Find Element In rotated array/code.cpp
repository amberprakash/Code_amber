#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = -1;
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int mid = (l + (h - l) / 2);
        if(arr[mid]==x){
            ans=mid;
            break;
        }else if(arr[l]<=arr[mid]){
            if(arr[l]<=x && x<=arr[mid]){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }else if(arr[mid]<=arr[h]){
            if(arr[mid]<=x && x<=arr[h]){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
    }
    cout<<ans;

    return 0;
}