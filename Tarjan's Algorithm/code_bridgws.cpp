#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &graph, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<vector<int>> &bridges)
{
    static int time = 0;
    disc[u] = low[u] = time++;

    for (auto v : graph[u])
    {
        if (disc[v] == -1)
        {
            parent[v] = u;
            dfs(v, graph, disc, low, parent, bridges);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
            {
                bridges.push_back({u, v});
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    return;
}

void find_bridges_tarjan(vector<vector<int>> &graph, int n, int e)
{
    vector<int> disc(n, -1), low(n, -1), parent(n, -1);
    vector<vector<int>> bridges;
    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            dfs(i, graph, disc, low, parent, bridges);
        }
    }
    for (auto &it : bridges)
    {
        cout << it[0] << " " << it[1] << endl;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    find_bridges_tarjan(graph, n, e);
    return 0;
}