#include <bits/stdc++.h>
using namespace std;

int mcm(int[], int, int);

int main()
{
    int arr[] = {40, 20, 30, 10, 30};

    int n = sizeof(arr) / sizeof(arr[0]);

    int cost = mcm(arr, 1, n - 1);

    cout << cost << endl;

    return 0;
}

int mcm(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    int mn = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        if (temp < mn)
            mn = temp;
    }

    return mn;
}