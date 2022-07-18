#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return root;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto temp = q.front();
                q.pop();
                if (i == n - 1)
                {
                    temp->next = NULL;
                    if (temp->left)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }
                else
                {
                    auto val = q.front();
                    temp->next = val;

                    if (temp->left)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
        }
        return root;
    }
};
int main()
{

    return 0;
}