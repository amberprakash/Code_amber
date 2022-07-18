#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int ans;
void solve(vector<int> arr, int ind, int at, int most, int count, int n, int sum)
{

    if (count <= most && count >= at)
    {
        ans = min(ans, sum);
    }
    if (ind == n)
    {
        return;
    }
    if (count == at)
    {
        return;
    }

    solve(arr, ind + 1, at, most, count + 1, n, sum + arr[ind]);
    solve(arr, ind + 1, at, most, count, n, sum);
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        ans = INT_MAX;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int q;
        cin>>q;
        vector<int>temp;
        while(q--){
        int l, r, atleast, atmost;
        cin >> l >> r >> atleast >> atmost;
        solve(arr, l - 1, atleast, atmost, 0, r, 0);
        temp.push_back(ans);
        
        ans=INT_MAX;
       }
       for(int i=0;i<temp.size();i++){
           cout<<temp[i]<<" ";
       }
       cout<<endl;
       ans=INT_MAX;
    }
    return 0;
}