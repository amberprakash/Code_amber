#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>> &graph, int node, int d, vector<bool> &visited)
{
    int total = 0;
    visited[node] = 1;
    if (d == 0)
    {
        return 1;
    }
    for (auto &p : graph[node])
    {
        if (visited[p] == 0)
        {
            total += dfs(graph, p, d - 1, visited);
        }
    }
    return total;
}
int func(vector<vector<int>> &graph, int start, int n1, int d, vector<bool> &visited)
{
    visited[start] = 1;
    int count = 0;
    if (n1 == start)
    {
        count += dfs(graph, n1, d, visited);
        return count;
    }

    else
    {

        for (auto &t : graph[start])
        {
            if (visited[t] == 0)
            {
                count += func(graph, t, n1, d, visited);
            }
        }
    }
    return count;
}
vector<int> solve(int n, vector<vector<int>> &graph, int q, vector<vector<int>> queries)
{   vector<int>ans;
    for(auto &f:queries){
        int l;
        vector<bool>visited(n+1,0);
        int a,b;
        a=f[0];
        b=f[1];
        l=func(graph,1,a,b,visited);
        ans.push_back(l);
    }
    return ans;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int q;
    cin>>q;
    vector<vector<int>> queries;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        queries.push_back(temp);
    }
    vector<int>ans=solve(n,graph,q,queries);
    for(auto &x:ans){
        cout<<x<<" ";
    }


    return 0;
}