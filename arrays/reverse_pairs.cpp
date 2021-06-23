#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int left, int mid, int right)
{
    int ans = 0;

    int j = mid + 1;

    for (int i = left; i <= mid; i++)
    {
        while (j <= right && nums[i] > 2LL * nums[j])
        {
            j++;
        }
        ans += (j - (mid + 1));
    }

    vector<int> temp;

    int l = left, r = mid + 1;

    while (l <= mid && r <= right)
    {
        if (nums[l] <= nums[r])
            temp.push_back(nums[left++]);
        else
            temp.push_back(nums[right++]);
    }

    while (l <= mid)
    {
        temp.push_back(nums[left++]);
    }

    while (r <= right)
    {
        temp.push_back(nums[right++]);
    }

    for (int i = left; i <= right; i++)
    {
        nums[i] = temp[i - left];
    }

    return ans;
}

int mergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return 0;
    int mid = (left + right) / 2;

    int ans = mergeSort(nums, left, mid);
    ans += mergeSort(nums, mid + 1, right);
    ans += merge(nums, left, mid, right);

    return ans;
}

int reversePairs(vector<int> &nums)
{
    int ans = mergeSort(nums, 0, nums.size() - 1);
    return ans;
}

int main()
{
    int n;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    int ans = reversePairs(v);

    cout << ans << endl;

    return 0;
}