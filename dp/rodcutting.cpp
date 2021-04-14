#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int rodcutting(int[], int[], int, int);

int main()
{
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};

    int N = 8;

    int n = sizeof(length) / sizeof(length[0]);

    int answer = rodcutting(length, price, N, n);

    cout << answer << endl;

    return 0;
}

int rodcutting(int length[], int price[], int N, int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][N];
}