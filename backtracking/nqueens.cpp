#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<string> board, int row, int column, int n)
{
    int tempr = row;
    int tempc = column;

    while (row >= 0 && column >= 0)
    {
        if (board[row][column] == 'Q')
        {
            return false;
        }
        row--;
        column--;
    }

    row = tempr;
    column = tempc;

    while (column >= 0)
    {
        if (board[row][column] == 'Q')
        {
            return false;
        }
        column--;
    }

    row = tempr;
    column = tempc;

    while (row < n && column >= 0)
    {
        if (board[row][column] == 'Q')
        {
            return false;
        }
        row++;
        column--;
    }

    return true;
}

void solve(int column, int n, vector<string> &board, vector<vector<string>> &ans)
{
    if (column == n)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (is_safe(board, i, column, n))
        {
            board[i][column] = 'Q';
            solve(column + 1, n, board, ans);
            board[i][column] = '.';
        }
    }
}

int main()
{
    int n, index = 0;

    cin >> n;

    string s(n, '.');
    vector<string> board(n);
    vector<vector<string>> ans;

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    solve(index, n, board, ans);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}