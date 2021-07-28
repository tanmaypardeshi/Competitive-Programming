/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
If the array is already sorted, then the inversion count is 0, but if the array is sorted 
in the reverse order, the inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 
*/

#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;

    int ans = 0;

    i = left;
    j = mid;
    k = left;

    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            ans = ans + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return ans;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, ans = 0;

    if (right > left)
    {
        mid = (left + right) / 2;

        ans += mergeSort(arr, temp, left, mid);
        ans += mergeSort(arr, temp, mid + 1, right);

        ans += merge(arr, temp, left, mid + 1, right);
    }
    return ans;
}

int main()
{
    int n;

    cin >> n;

    int *arr = new int[n];
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = mergeSort(arr, temp, 0, n - 1);

    cout << ans << endl;

    return 0;
}