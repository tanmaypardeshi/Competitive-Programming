/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
*/
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    int ans;

    for (int i = 0; i < n; i++)
    {
        if (mp[nums[i]] > (n / 2))
            ans = nums[i];
    }
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

    int ans = majorityElement(v);

    cout << ans << endl;

    return 0;
}