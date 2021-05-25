#include <bits/stdc++.h>
using namespace std;

bool subsetsum(int[], int, int);
bool dp[1000][1000];

int main()
{
    int arr[] = {2, 3, 5, 6, 7, 8};
    int sum = 1;

    int n = sizeof(arr) / sizeof(arr[0]);

    bool result = subsetsum(arr, n, sum);

    if (result == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

bool subsetsum(int arr[], int n, int sum)
{
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }

    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }

    return dp[n][sum];
}