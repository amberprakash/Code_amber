#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool check(int i, int j, int N)
{
    if (i < 0 || j < 0 || i >= N || j >= N)
        return false;

    return true;
}

// Function to find out minimum steps Knight needs to reach target position.
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    pair<int, int> start = {KnightPos[0] - 1, KnightPos[1] - 1};
    pair<int, int> end = {TargetPos[0] - 1, TargetPos[1] - 1};

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    int level = 0;

    vector<pair<int, int>> cord = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, 1}, {2, -1}, {-2, -1}, {-2, 1}};

    while (!q.empty())
    {
        int size = q.size();
        for (int c = 0; c < size; c++)
        {

            int i = q.front().first;
            int j = q.front().second;

            if (q.front() == end)
                return level;

            for (int k = 0; k < 8; k++)
            {
                int x = cord[k].first;
                int y = cord[k].second;

                if (check(i + x, j + y, N) && !visited[i + x][j + y])
                {
                    q.push({i + x, j + y});
                    visited[i + x][j + y] = true;
                }
            }

            q.pop();
        }
        level++;
    }

    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> knightPosition;
    vector<int> targetPosition;
    int a, b;
    cin >> a >> b;
    knightPosition.push_back(a);
    knightPosition.push_back(b);
    int x, y;
    cin >> x >> y;
    targetPosition.push_back(x);
    targetPosition.push_back(y);
    int temp = minStepToReachTarget(knightPosition, targetPosition, n);
    cout << temp;
    return 0;
}