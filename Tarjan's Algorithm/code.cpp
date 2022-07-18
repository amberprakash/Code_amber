// Strongly Connected Component

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void dfs(int u, vector<vector<int>> &graph, vector<int> &disc, vector<int> &low, stack<int> &mystack, vector<bool> &inStack)
{
    static int time = 0;
    disc[u] = low[u] = time++;
    mystack.push(u);
    inStack[u] = true;
    for (auto v : graph[u])
    {
        if (disc[v] == -1)
        {
            dfs(v, graph, disc, low, mystack, inStack);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (low[u] == disc[u])
    {
        cout << "SCC is : ";
        while (mystack.top() != u)
        {
            cout << mystack.top() << " ";
            inStack[mystack.top()] = false;
            mystack.pop();
        }
        cout << mystack.top() << " " << endl;
        inStack[mystack.top()] = false;
        mystack.pop();
    }
    return;
}
void findSSC_tarjan(vector<vector<int>> &graph, int n, int e)
{
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> inStack(n, false);
    stack<int> mystak;

    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
        {
            dfs(i, graph, disc, low, mystak, inStack);
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
    }
    findSSC_tarjan(graph, n, e);
    return 0;
}