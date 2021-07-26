/*
Given an array nums of n integers, return an array of all the unique 
quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector<int> &nums, int target)
{
    vector<vector<int>> res;

    if (nums.empty())
    {
        return res;
    }

    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target_2 = target - nums[i] - nums[j];
            int front = j + 1;
            int back = n - 1;

            while (front < back)
            {
                int two_sum = nums[front] + nums[back];

                if (two_sum < target_2)
                    front++;
                else if (two_sum > target_2)
                    back--;
                else
                {
                    vector<int> quad(4, 0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[front];
                    quad[3] = nums[back];
                    res.push_back(quad);

                    // Processing duplicates of number 3
                    while (front < back && nums[front] == quad[2])
                        ++front;
                    // Processing duplicates of number 4
                    while (front < back && nums[back] == quad[3])
                        --back;
                }
            }
            // Processing the duplicates of number 2
            while (j + 1 < n && nums[j + 1] == nums[j])
                ++j;
        }
        // Processing the duplicates of number 1
        while (i + 1 < n && nums[i + 1] == nums[i])
            ++i;
    }
    return res;
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

    vector<vector<int>> ans = four_sum(v, target);

    cout << "The values are:- ";
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}