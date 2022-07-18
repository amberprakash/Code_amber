#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
unordered_map<string, int> mp;
string solve(Node *root)
{
    if (root == NULL)
    {
        return "$";
    }
    string s = "";
    if (root->left == NULL and root->right == NULL)
    {
        s = to_string(root->data);
        return s;
    }
    s = s + to_string(root->data);
    s = s + solve(root->left);
    s = s + solve(root->right);
    mp[s]++;
    return s;
}
int main()
{

    return 0;
}