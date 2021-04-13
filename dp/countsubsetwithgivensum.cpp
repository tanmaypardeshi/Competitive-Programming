#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int countsubsetwithgivensum(int[], int, int);

int main()
{
    int array[] = {1, 2, 7};
    int sum = 10;

    int n = sizeof(array) / sizeof(array[0]);
    int number = countsubsetwithgivensum(array, n, sum);

    cout << number << endl;
    return 0;
}

int countsubsetwithgivensum(int array[], int n, int sum)
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
            if (array[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i - 1][j - array[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}