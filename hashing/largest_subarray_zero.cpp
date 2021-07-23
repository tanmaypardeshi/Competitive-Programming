/*
Given an array having both positive and negative integers. 
The task is to compute the length of the largest subarray with sum 0.
*/

#include <bits/stdc++.h>
using namespace std;

int largest_subarray_zero(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int maxi = 0, sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mp.find(sum) != mp.end())
            {
                maxi = max(maxi, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    return maxi;
}

int main()
{
    int n;
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

    int answer = largest_subarray_zero(v);

    cout << "Largest subarray with zero sum is:- " << answer << endl;

    return 0;
}