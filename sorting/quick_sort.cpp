#include <bits/stdc++.h>
using namespace std;

void quick_sort(int arr[], int l, int r)
{
    int pivot_el = arr[l];
    int low = l + 1, high = r;

    while (low <= high)
    {
        while (arr[low] < pivot_el)
        {
            low++;
        }
        while (arr[high] > pivot_el)
        {
            high--;
        }

        if (low < high)
        {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
    arr[l] = arr[high];
    arr[high] = pivot_el;
    high--;

    if (l < high)
        quick_sort(arr, l, high);

    if (low < r)
    {
        quick_sort(arr, low, r);
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

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}