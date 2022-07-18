#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void dfs(int u, vector<vector<int>> &graph, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &articPoint)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;
    int children = 0;

    for (auto v : graph[u])
    {
        if (disc[v] == -1)
        {
            children += 1;
            parent[v] = u;
            dfs(v, graph, disc, low, parent, articPoint);
            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && children > 1)
            {
                articPoint[u] = true;
            }
            if (parent[u] != -1 && low[v] >= disc[u])
            {
                articPoint[u] = true;
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    return;
}
void find_ArticulationPoint(vector<vector<int>> graph, int n, int e)
{
    vector<int> disc(n, -1), low(n, -1), parent(n, -1);
    vector<bool> articPoint(n, false);
    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            dfs(i, graph, disc, low, parent, articPoint);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (articPoint[i] == true)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> graph(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    find_ArticulationPoint(graph, n, e);

    return 0;
}