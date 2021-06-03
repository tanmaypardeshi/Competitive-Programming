/* 
Given an integer numRows, return the first numRows of Pascal's triangle.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> row;
        if (i == 0)
            row.push_back(1);
        else if (i == 1)
        {
            row.push_back(1);
            row.push_back(1);
        }
        else
        {
            row.push_back(1);
            for (int j = 0; j < i - 1; j++)
            {
                row.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            }
            row.push_back(1);
        }
        ans.push_back(row);
    }
    return ans;
}

int main()
{
    int n;

    cin >> n;

    vector<vector<int>> ans = generate(n);

    for (auto x : ans)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}