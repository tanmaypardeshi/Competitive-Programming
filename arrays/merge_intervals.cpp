/*
Given an array of intervals where intervals[i] = [starti, endi], merge 
all overlapping intervals, and return an array of the non-overlapping 
intervals that cover all the intervals in the input.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    int j = 0;
    int i = 1;
    while (i < intervals.size())
    {
        if (ans[j][1] >= intervals[i][0])
        {
            ans[j][1] = max(ans[j][1], intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
            ++j;
        }
        ++i;
    }
    return ans;
}

int main()
{
    vector<vector<int>> v;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        int a, b;
        cin >> a >> b;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }

    vector<vector<int>> ans = merge(v);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}