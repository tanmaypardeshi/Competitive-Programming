#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int countsubsetwithgivendifference(int[], int, int);

int main()
{
    int array[] = {1, 3, 2, 1};
    int difference = 1;

    int sum = 0;

    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }

    int value = (sum + difference) / 2;
    int count = countsubsetwithgivendifference(array, n, value);

    cout << count << endl;

    return 0;
}

int countsubsetwithgivendifference(int array[], int n, int value)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < value + 1; j++)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < value + 1; j++)
        {
            if (array[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i - 1][j - array[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][value];
}