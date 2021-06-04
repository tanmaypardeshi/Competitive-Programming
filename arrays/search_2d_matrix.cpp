/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int columns = matrix[0].size();

    for (int i = 0; i < rows; i++)
    {
        if (target <= matrix[i][columns - 1])
        {
            for (int j = columns - 1; j >= 0; j--)
            {
                if (target == matrix[i][j])
                    return true;
            }
        }
    }
    return false;
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

    int target;
    cin >> target;

    bool ans = searchMatrix(v, target);

    cout << ans << endl;

    return 0;
}