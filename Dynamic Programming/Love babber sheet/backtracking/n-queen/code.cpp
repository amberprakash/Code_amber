#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<vector<string>> queen;
void solve(vector<vector<string>> &board, vector<bool> &cols, vector<bool> &ldia, vector<bool> &rdia, int row, vector<int> &temp)
{
    if (row == board.size())
    {
        ans.push_back(temp);
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
        return;
    }
    for (int col = 0; col < board[0].size(); col++)
    {
        if (cols[col] == false && ldia[col + row] == false && rdia[row - col + board.size() - 1] == false)
        {
            board[row][col] = "Q";
            cols[col] = true;
            ldia[row + col] = true;
            rdia[row - col + board.size() - 1] = true;
            temp.push_back(col + 1);
            solve(board, cols, ldia, rdia, row + 1, temp);
            board[row][col] = ".";
            cols[col] = false;
            ldia[row + col] = false;
            rdia[row - col + board.size() - 1] = false;
            temp.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<bool> cols(n, false);
    vector<bool> ldia(2 * n - 1, false);
    vector<bool> rdia(2 * n - 1, false);
    vector<int> temp = {};
    vector<vector<string>> board(n, vector<string>(n, "."));
    solve(board, cols, ldia, rdia, 0, temp);

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}