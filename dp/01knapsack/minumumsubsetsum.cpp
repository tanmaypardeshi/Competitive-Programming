#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int minimumsubsetsum(int[], int, int);

int main()
{
    int array[] = {1, 12, 5, 6};
    int n = sizeof(array) / sizeof(array[0]);

    int range = 0;

    for (int i = 0; i < n; i++)
    {
        range += array[i];
    }

    int diff = minimumsubsetsum(array, n, range);

    cout << diff << endl;
    return 0;
}

int minimumsubsetsum(int array[], int n, int range)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
        {
            if (i == 0)
                t[i][j] = false;
            if (j == 0)
                t[i][j] = true;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < range + 1; j++)
        {
            if (array[i - 1] <= j)
                t[i][j] = t[i - 1][j] || t[i - 1][j - array[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    int mn = INT32_MAX;
    for (int j = range / 2; j >= 0; j--)
    {
        if (t[n][j] == true)
        {
            mn = range - 2 * j;
            break;
        }
    }
    return mn;
}
