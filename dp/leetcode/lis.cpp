#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &nums)
{
    vector<int> lis(nums.size(), 1);

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    return *max_element(lis.begin(), lis.end());
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int ans = lis(nums);

    cout << ans << endl;

    return 0;
}