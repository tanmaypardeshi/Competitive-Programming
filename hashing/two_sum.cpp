/*
Given an array of integers nums and an integer target, return indices 
of the two numbers such that they add up to target. You may assume that 
each input would have exactly one solution, and you may not use the same 
element twice. You can return the answer in any order.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> two_sum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) == mp.end())
        {
            mp[nums[i]] = i;
        }
        else
        {
            ans.push_back(mp[target - nums[i]]);
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    int n, target;

    cout << "Enter n:- ";
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cout << "Enter v[" << i << "]:- ";
        cin >> temp;
        v.push_back(temp);
    }

    cout << "Enter target:- ";
    cin >> target;

    vector<int> ans = two_sum(v, target);

    cout << "The values are:- ";
    for (auto x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}