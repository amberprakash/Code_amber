#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
void solve(int h, int l, string s)
{
    string temp = s.substr(l, h - l + 1);
    mp[temp]++;
}
void convert(int i, int j, string &s)
{
    while (i <= j)
    {
        s[i] = tolower(s[i]);
        i++;
    }
}

int main()
{
    string s;
    getline(cin, s);

    
    int h = 0;
    int l = 0;
    int n = s.length();
    while (h < n)
    {
        if (s[h] == ' ')
        {
            convert(l, h - 1, s);
            solve(h - 1, l, s);

            l = h + 1;
        }
        if (h == n - 1)
        {
            convert(l, h, s);
            solve(h, l, s);
        }
        h++;
    }
    for (auto x : mp)
    {
        if (x.second > 1)
        {
            cout << x.first << " " << x.second << endl;
        }
    }
    return 0;
}