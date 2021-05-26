#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int mcm(int[], int, int);

int main()
{
    int arr[] = {40, 20, 30, 10, 30};

    int n = sizeof(arr) / sizeof(arr[0]);

    memset(t, -1, sizeof(t));

    int cost = mcm(arr, 1, n - 1);

    cout << cost << endl;

    return 0;
}

int mcm(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int mn = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[j] * arr[k];

        if (temp < mn)
            mn = temp;
    }

    return t[i][j] = mn;
}