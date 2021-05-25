#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int unbounded(int[], int[], int, int);

int main()
{
    int wt[] = {1, 50};
    int val[] = {1, 30};
    int W = 100;

    int n = sizeof(wt) / sizeof(wt[0]);

    int answer = unbounded(wt, val, n, W);

    cout << answer << endl;

    return 0;
}

int unbounded(int wt[], int val[], int n, int W)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - i][j];
            }
        }
    }

    return t[n][W];
}