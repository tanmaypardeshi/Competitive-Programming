#include <bits/stdc++.h>
using namespace std;

int max_prod_subarray(vector<int> &nums)
{
    int max_overall = nums[0];
    int max_here = nums[0], min_here = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int temp = max_here;
        max_here = max({nums[i], nums[i] * temp, nums[i] * min_here});
        min_here = min({nums[i], nums[i] * temp, nums[i] * min_here});
        max_overall = max(max_overall, max_here);
    }
    return max_overall;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int ans = max_prod_subarray(v);

    cout << ans << endl;

    return 0;
}