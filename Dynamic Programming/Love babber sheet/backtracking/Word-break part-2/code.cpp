#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void solve(vector<string> &dict, string s, string ans, vector<string> &temp)
{
    if (s.length() == 0)
    {
        ans.pop_back();
        temp.push_back(ans);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string left = s.substr(0, i + 1);
        if (find(dict.begin(), dict.end(), left) != dict.end())
        {
            string right = s.substr(i + 1, s.length() - (i + 1));
            solve(dict, right, ans + left + " ", temp);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    string s;
    cin >> s;
    string ans = "";
    vector<string> temp;
    solve(dict, s, ans, temp);
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << endl;
    }
    return 0;
}