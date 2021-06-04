/*
You are given an n x n 2D matrix representing an image, 
rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you 
have to modify the input 2D matrix directly. DO NOT allocate 
another 2D matrix and do the rotation.
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    vector<vector<int>> temp = matrix;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = matrix[0].size() - 1; j >= 0; j--)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            row.push_back(temp);
        }
        v.push_back(row);
    }

    rotate(v);

    return 0;
}