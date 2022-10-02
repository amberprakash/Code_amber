#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
set<string> st;
vector<string> ans;

int lcsLength(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

void lcs(string s, string t, int i, int j, string &temp, int count)
{

    if (count == 0)
    {
        if (st.find(temp) == st.end())
        {
            st.insert(temp);
            ans.push_back(temp);
        }

        return;
    }
    if (i >= s.size() || j >= t.size())
        return;

    for (int r = i; r < s.size(); r++)
    {
        for (int c = j; c < t.size(); c++)
        {
            if (s[r] == t[c])
            {

                temp.push_back(s[r]);
                lcs(s, t, r + 1, c + 1, temp, count - 1);
                temp.pop_back();
            }
        }
    }
}

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.length();
    int m = t.length();
    int length = lcsLength(s, t);
    string temp = "";
    lcs(s, t, 0, 0, temp, length);
    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}