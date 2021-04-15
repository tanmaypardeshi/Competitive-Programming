#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int lcs(string, string, int, int);

int main()
{
    string x, y;

    cin >> x >> y;

    int count = lcs(x, y, x.size(), y.size());

    cout << count << endl;

    return 0;
}

int lcs(string x, string y, int m, int n)
{
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }
    return t[m][n];
}