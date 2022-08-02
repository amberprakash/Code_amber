#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
void solve(vector<string> temp, int pos, string s, string str)
{
    if (pos == s.length())
    {
        ans.push_back(str);
        return;
    }
    for (auto x : temp[s[pos] - '0'])
    {
        str.push_back(x);
        solve(temp, pos + 1, s, str);
        str.pop_back();
    }
    return;
}
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    if (n == 0)
    {
        cout << "NULL";
    }
    else
    {
        vector<string> temp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(temp, 0, s, "");
        for (auto &x : ans)
        {
            cout << x << " ";
        }
    }
    return 0;
}