#include <bits/stdc++.h>
using namespace std;

int lcs(string, string, int, int);
int t[1000][1000];

int main()
{
    string x, y;
    int i, j, scs, lc;

    cin >> x >> y;

    i = x.length();
    j = y.length();

    lc = lcs(x, y, i, j);

    scs = i + j - lc;

    cout << scs << endl;
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
                t[i][j] = t[i - 1][j - 1] + 1;
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    return t[m][n];
}