/*
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/

#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    vector<vector<int>> temp;
    int r = matrix.size(), c = matrix[0].size();
    for (int i = 0; i < r; i++)
    {
        temp.push_back(matrix[i]);
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (temp[i][j] == 0)
            {
                for (int k = 0; k < r; k++)
                {
                    matrix[k][j] = 0;
                }
                for (int l = 0; l < c; l++)
                {
                    matrix[i][l] = 0;
                }
            }
        }
    }
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

    setZeroes(v);

    for (auto x : v)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}