#include <bits/stdc++.h>
using namespace std;

int find_min_index(vector<int> nums, int left, int right)
{
    int n = nums.size();
    while (left <= right)
    {
        if (nums[left] <= nums[right])
        {
            return left;
        }

        int mid = left + (right - left) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
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
    return -1;
}

int binary_search(vector<int> v, int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (v[mid] == key)
        {
            return key;
        }
        else if (key > v[mid])
        {
            return binary_search(v, mid + 1, right, key);
        }
        else
        {
            return binary_search(v, left, mid - 1, key);
        }
    }

    return -1;
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

    int key;

    cout << "Enter key:- ";
    cin >> key;

    int index = find_min_index(v, 0, v.size());

    cout << "Index of minimum element = " << index << endl;

    int answer = binary_search(v, 0, index - 1, key);
    if (answer == -1)
    {
        answer = binary_search(v, index, v.size() - 1, key);
    }

    if (answer != -1)
    {
        cout << key << " is present in array" << endl;
    }
    else
    {
        cout << key << " not found in array" << endl;
    }

    return 0;
}