#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> nums, int left, int right)
{
    int n = nums.size();
    int mid = 0;
    int i = 0;
    while (left <= right)
    {

        if (nums[left] <= nums[right])
        {
            return left;
        }

        mid = left + (right - left) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev])
        {
            return mid;
        }
        else if (nums[0] <= nums[mid])
        {
            left = mid + 1;
        }
        else if (nums[mid] <= nums[n - 1])
        {
            right = mid - 1;
        }
    }
    return mid;
}

int main()
{
    vector<int> v;

    int n;
    cout << "Enter size:- ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cout << "Enter arr[" << i << "]:- ";
        cin >> temp;
        v.push_back(temp);
    }

    int answer = binary_search(v, 0, v.size() - 1);

    cout << "The array has been rotated " << answer << " times" << endl;

    return 0;
}