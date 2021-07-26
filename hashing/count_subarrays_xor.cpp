/*
Given an array of integers arr[] and a number m, 
count the number of subarrays having XOR of their 
elements as m.
*/

#include <bits/stdc++.h>
using namespace std;

int count_subarrays_xor(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    int cnt = 0;
    int xorr = 0;

    for (auto x : nums)
    {
        xorr = xorr ^ x;

        if (xorr == k)
        {
            cnt++;
        }
        if (freq.find(xorr ^ k) != freq.end())
        {
            cnt += freq[xorr ^ k];
        }

        freq[xorr] += 1;
    }
    return cnt;
}

int main()
{
    int n, k;
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

    cout << "Enter k:- ";
    cin >> k;

    int answer = count_subarrays_xor(v, k);

    cout << "Number of subarrays with target as " << k << " are:- " << answer << endl;

    return 0;
}