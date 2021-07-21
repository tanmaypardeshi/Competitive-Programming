#include <bits/stdc++.h>
using namespace std;

int min_platforms(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platforms = 1, i = 1, j = 0, result = 1;

    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            platforms++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            platforms--;
            j++;
        }

        if (platforms > result)
        {
            result = platforms;
        }
    }

    return result;
}

int main()
{
    int n;

    cout << "Enter n:- ";
    cin >> n;

    int *arr = new int[n];
    int *dep = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]:- ";
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter dep[" << i << "]:- ";
        cin >> dep[i];
    }

    int ans = min_platforms(arr, dep, n);

    cout << "Minimum platforms needed are:- " << ans << endl;

    return 0;
}