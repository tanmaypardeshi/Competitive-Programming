#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int low, int mid, int high)
{
    int cnt = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && nums[i] > 2LL * nums[j])
        {
            j++;
        }
        cnt += (j - (mid + 1));
    }

    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left++]);
        }
        else
        {
            temp.push_back(nums[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(nums[left++]);
    }
    while (right <= high)
    {
        temp.push_back(nums[right++]);
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }

    return cnt;
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