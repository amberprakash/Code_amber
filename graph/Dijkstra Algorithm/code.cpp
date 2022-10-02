#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// Shortest path from source vertex to all vertex

vector<int> dijkstra(vector<vector<pair<int, int>>> graph, int v, int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    vector<int> visit(v, false);
    vector<int> dis(v, INT_MAX);
    dis[s]=0;
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        if (!visit[node.second])
        {
            for (auto x : graph[node.second])
            {
                if(dis[x.first]>x.second+node.first){
                    dis[x.first]=x.second+node.first;
                    pq.push({dis[x.first],x.first});
                }
            }
        }
        visit[node.second]=true;
    }
    return dis;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int>>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    int S;
    cin >> S;
    vector<int> ans;
    ans = dijkstra(graph, v, S);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}