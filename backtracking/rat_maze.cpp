#include <bits/stdc++.h>
#define N 4
using namespace std;

bool isSafe(int maze[N][N], int x, int y)
{
    if (
        x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{

    if (x == N - 1 && y == N - 1)
    {
        sol[x][y] = 1;
        return true;
    }
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    if (isSafe(maze, x, y))
    {
        if (sol[x][y] == 1)
        {
            return false;
        }

        sol[x][y] = 1;

        for (auto a : directions)
        {
            int new_row = x + a.first;
            int new_col = y + a.second;

            if (solveMazeUtil(maze, new_row, new_col, sol))
                return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

bool solveMaze(int maze[N][N])
{
    int sol[N][N] = {{0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}};

    if (solveMazeUtil(
            maze, 0, 0, sol) == false)
    {
        cout << "Solution doesn't exist" << endl;
        return false;
    }

    printSolution(sol);
    return true;
}

int main()
{
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};

    solveMaze(maze);
    return 0;
}