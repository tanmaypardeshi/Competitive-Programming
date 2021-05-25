// Coin Change 1 - Maximum number of ways

#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int coinchange1(int[], int, int);

int main()
{
    int coin[] = {1, 2, 3};

    int sum = 4;

    int n = sizeof(coin) / sizeof(coin[0]);

    int answer = coinchange1(coin, sum, n);

    cout << answer << endl;

    return 0;
}

int coinchange1(int coin[], int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i][j - coin[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}