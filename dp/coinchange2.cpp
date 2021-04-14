// Coin Change 1 - Minimum number of coins

#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int coinchange2(int[], int, int);

int main()
{
    int coin[] = {25, 10, 5};

    int sum = 30;

    int n = sizeof(coin) / sizeof(coin[0]);

    int answer = coinchange2(coin, sum, n);

    cout << answer << endl;

    return 0;
}

int coinchange2(int coin[], int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = INT32_MAX - 1;
            if (j == 0)
                t[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        if (i % coin[0] == 0)
        {
            t[1][i] = i / coin[0];
        }
        else
        {
            t[1][i] = INT32_MAX - 1;
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
                t[i][j] = min(t[i - 1][j], t[i][j - coin[i - 1]]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}