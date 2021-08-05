#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l1, int r1, int l2, int r2)
{
    int a, b, k, temp[100];
    k = 0;
    a = l1;
    b = l2;

    while (a <= r1 && b <= r2)
    {
        if (arr[a] < arr[b])
        {
            temp[k] = arr[a];
            a++;
            k++;
        }
        else
        {
            temp[k] = arr[b];
            b++;
            k++;
        }
    }

    while (a <= r1)
    {
        temp[k] = arr[a];
        a++;
        k++;
    }

    while (b <= r2)
    {
        temp[k] = arr[b];
        b++;
        k++;
    }

    k = 0;

    for (a = l1; a <= r2; a++)
    {
        arr[a] = temp[k];
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, mid + 1, right);
    }
}

int main()
{
    int n, *arr;

    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}