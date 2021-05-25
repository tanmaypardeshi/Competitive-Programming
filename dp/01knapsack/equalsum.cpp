#include <bits/stdc++.h>
using namespace std;

bool dp[1000][1000];
bool equalsum(int[], int, int);

int main()
{
    int arr[] = {2, 4, 12, 8};
    int sum = 0;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        cout << "No" << endl;
        return 0;
    }

    else
    {
        bool result = equalsum(arr, n, sum / 2);
        if (result == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

bool equalsum(int arr[], int n, int sum)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}