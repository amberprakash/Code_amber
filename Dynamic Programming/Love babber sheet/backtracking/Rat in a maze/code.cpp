#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
void solve(vector<vector<int>> &m, vector<vector<int>> &visit, int i, int j, int n, string s)
{
    if (i < 0 || j < 0 || i >= n || j >= n || visit[i][j] == 1 || m[i][j] == 0)
    {
        return;
    }
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(s);
        return;
    }
    visit[i][j] = 1;
    s = s + "R";
    solve(m, visit, i, j + 1, n, s);
    s.pop_back();
    s = s + "L";
    solve(m, visit, i, j - 1, n, s);
    s.pop_back();
    s = s + "U";
    solve(m, visit, i - 1, j, n, s);
    s.pop_back();
    s = s + "D";
    solve(m, visit, i + 1, j, n, s);
    s.pop_back();
    visit[i][j] = 0;
}
int main()
{   int n;
    cin>>n;
    vector<vector<int>>m(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }
    vector<vector<int>>visit(n,vector<int>(n,0));
    string s="";
    solve(m,visit,0,0,n,s);
    for(auto &it:ans){
        cout<<it<<endl;
    }

    return 0;
}