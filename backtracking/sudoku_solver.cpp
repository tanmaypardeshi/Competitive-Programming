#include <bits/stdc++.h>
using namespace std;

bool is_valid(vector<vector<char>> &board, int row, int column, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][column] == c)
            return false;
        if (board[row][i] == c)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (column / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char k = '1'; k <= '9'; k++)
                {
                    if (is_valid(board, i, j, k))
                    {
                        board[i][j] = k;
                        if (solve(board) == true)
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board = {{'3', '.', '6', '5', '.', '8', '4', '.', '.'},
                                  {'5', '2', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', '8', '7', '.', '.', '.', '.', '3', '1'},
                                  {'.', '.', '3', '.', '1', '.', '.', '8', '.'},
                                  {'9', '.', '.', '8', '6', '3', '.', '.', '5'},
                                  {'.', '5', '.', '.', '9', '.', '6', '.', '.'},
                                  {'1', '3', '.', '.', '.', '.', '2', '5', '.'},
                                  {'.', '.', '.', '.', '.', '.', '.', '7', '4'},
                                  {'.', '.', '5', '2', '.', '6', '3', '.', '.'}};
    solve(board);

    for (auto x : board)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}
