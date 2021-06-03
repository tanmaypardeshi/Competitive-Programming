/*
Given an array of integers nums containing n + 1 
integers where each integer is in the range [1, n] inclusive.
*/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            return nums[i];
    }
    return -1;
}

int findDuplicateOptimised(vector<int> &nums)
{
    set<int> s;

    for (auto x : nums)
    {
        if (s.find(x) != s.end())
        {
            return x;
        }
        s.insert(x);
    }
    return -1;
}

int main()
{
    vector<int> v;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << endl;
    cout << findDuplicate(v) << endl;
    cout << findDuplicateOptimised(v) << endl;

    return 0;
}
