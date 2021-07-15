#include <bits/stdc++.h>
using namespace std;

int search(int **mat, int key, int n, int m)
{
    int i = 0, j = m - 1;

    while (i >= 0 && i < n && j > 0 && j < m)
    {
        if (mat[i][j] == key)
        {
            return mat[i][j];
        }
        else if (mat[i][j] > key)
        {
            j--;
        }
        else if (mat[i][j] < key)
        {
            i++;
        }
    }
    return -1;
}

int main()
{
    int n, m;

    cout << "Enter number of rows:- ";
    cin >> n;
    cout << "Enter number of columns:- ";
    cin >> m;

    int **mat = new int *[n];

    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[m];
    }

    cout << "\nEnter elements in the matrix:- " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "Enter mat[" << i << "][" << j << "]:- ";
            cin >> mat[i][j];
        }
    }

    cout << "\nMatrix is:- " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    int key;

    cout << "Enter key:- ";
    cin >> key;

    int answer = search(mat, key, n, m);

    if (answer != -1)
    {
        cout << key << " found in the array" << endl;
    }
    else
    {
        cout << key << " not found in the array" << endl;
    }

    return 0;
}