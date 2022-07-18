#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    int i = 0;
    TreeNode *solve(vector<int> &pre, int max_val)
    {
        if (i == pre.size() || pre[i] > max_val)
        {
            return NULL;
        }

        int curr_val = pre[i++];
        TreeNode *temp = new TreeNode(curr_val);
        temp->left = solve(pre, curr_val);
        temp->right = solve(pre, max_val);
        return temp;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return solve(preorder, INT_MAX);
    }
};
int main()
{

    return 0;
}