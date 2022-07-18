#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
bool solve(string a, string b)
{
    if (a.compare(b) == 0)
    {
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }
    string key=a;
    key.push_back(' ');
    key.append(b);
    if(mp.find(key)!=mp.end()){
        return mp[key];
    }
    int n = a.length();
    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        if (solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i)) || solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i)))
        {
            flag = true;
            break;
        }
    }
    return mp[key]=flag;
}
int main()
{
    string x, y;
    cin >> x;
    cin >> y;
    int n = x.length();
    int m = y.length();
    mp.clear();
    if (n != m)
    {
        cout << "FALSE" << endl;
    }
    if (n == 0 && m == 0)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        if (solve(x, y) == true)
        {
            cout << "TRUE";
        }
        else
        {
            cout << "FALSE";
        }
    }
    return 0;
}