/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
*/
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
    int dp[1000][1000];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    int m, n;

    cin >> m >> n;

    int ans = uniquePaths(m, n);

    cout << ans << endl;
    return 0;
}