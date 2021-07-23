/*
Given an unsorted array of integers nums, 
return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
*/

#include <bits/stdc++.h>
using namespace std;

int longest_consecutive_sequence(vector<int> &nums)
{
    unordered_set<int> s;
    for (auto x : nums)
    {
        s.insert(x);
    }
    int n = nums.size();
    int longest = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.find(nums[i] - 1) == s.end())
        {
            int length = 1;
            int x = nums[i];
            while (s.find(x + 1) != s.end())
            {
                x++;
                length++;
            }
            longest = max(longest, length);
        }
    }
    return longest;
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

    int answer = longest_consecutive_sequence(v);

    cout << "Longest consecutive sequence is:- " << answer << endl;

    return 0;
}