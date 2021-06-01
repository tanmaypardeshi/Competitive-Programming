/* 
Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order red, 
white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, 
respectively.

You must solve this problem without using the library's sort function.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                cnt_0++;
            else if (nums[i] == 1)
                cnt_1++;
            else
                cnt_2++;
        }
        int j = 0;
        int k = 0;
        while (k < cnt_0)
        {
            nums[j] = 0;
            j++;
            k++;
        }
        k = 0;
        while (k < cnt_1)
        {
            nums[j] = 1;
            j++;
            k++;
        }
        k = 0;
        while (k < cnt_2)
        {
            nums[j] = 2;
            j++;
            k++;
        }
    }
};

int main()
{
    Solution s;

    vector<int> nums;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    s.sortColors(nums);
}