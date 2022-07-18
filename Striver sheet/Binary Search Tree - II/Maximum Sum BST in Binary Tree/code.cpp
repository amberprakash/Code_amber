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
    struct tree
    {
        bool check;
        int minE, maxE, sum;
    };
    tree solve(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return {true, INT_MAX, INT_MIN, 0};
        }
        tree l = solve(root->left, ans);
        tree r = solve(root->right, ans);
        if (l.check && r.check && root->val > l.maxE && root->val < r.minE)
        {
            int total = root->val + l.sum + r.sum;
            ans = max(ans, total);
            return {true, min(root->val, l.minE), max(root->val, r.maxE), total};
        }
        else
        {
            return {false, 0, 0, 0};
        }
    }
    int maxSumBST(TreeNode *root)
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
int main()
{

    return 0;
}