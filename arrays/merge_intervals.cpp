/*
Given an array of intervals where intervals[i] = [starti, endi], merge 
all overlapping intervals, and return an array of the non-overlapping 
intervals that cover all the intervals in the input.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    bool flag = false;
    for (int i = 0; i < intervals.size() - 1; i++)
    {
        vector<int> temp;
        if (intervals[i][1] >= intervals[i + 1][0])
        {
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i + 1][1]);
            ans.push_back(temp);
            i++;
        }
        else
        {
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
            ans.push_back(temp);
        }
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