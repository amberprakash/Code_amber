#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    int k;
    cin >> k;
    vector<vector<int>> graph(k);
    vector<int> inDegree(k, 0);
    for (int i = 0; i < n - 1; i++)
    {
        auto a = dict[i];
        auto b = dict[i + 1];
        for (int j = 0; j < min(a.length(), b.length()); j++)
        {
            if (a[j] != b[j])
            {
                int x = a[j] - 'a';
                int y = b[j] - 'a';
                graph[x].push_back(y);
                inDegree[y]++;
                break;
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    string ans = "";
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        ans += cur + 'a';
        for (auto x : graph[cur])
        {
            inDegree[x]--;
            if (inDegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    cout << ans;

    return 0;
}