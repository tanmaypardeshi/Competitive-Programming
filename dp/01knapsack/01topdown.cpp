#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int knapsack(int[], int[], int, int);

int main()
{
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int W = 50;

    int n = sizeof(wt) / sizeof(wt[0]);

    cout << knapsack(wt, val, W, n) << endl;

    return 0;
}

int knapsack(int wt[], int val[], int W, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }

    return dp[n][W];
}
