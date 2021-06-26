/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Follow-up: Could you solve the problem in linear time and in O(1) space?
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    vector<int> ans;

    for (auto x : mp)
    {
        if (x.second > (n / 3))
            ans.push_back(x.first);
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

    vector<int> ans = majorityElement(v);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}