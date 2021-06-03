/*
Given an integer array nums, find the contiguous subarray 
(containing at least one number) which has the largest sum and return its sum.
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(int nums[], int n)
{
    int largest = nums[0];
    int sum = nums[0];

    for (int i = 1; i < n; i++)
    {
        sum = max(sum + nums[i], nums[i]);
        largest = max(largest, sum);
    }
    return largest;
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

    cout << maxSubArray(arr, n) << endl;

    return 0;
}