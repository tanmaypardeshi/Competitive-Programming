#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int lcs(string, string, int, int);

int main()
{
    string a, b, temp;
    int i, j, lc;

    cin >> a;
    temp = a;
    reverse(a.begin(), a.end());
    b = a;
    a = temp;
    i = a.length();
    j = b.length();

    lc = lcs(a, b, i, j);

    cout << a.length() - lc << endl;

    return 0;
}

int lcs(string a, string b, int m, int n)
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
            if (a[i - 1] == b[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    return t[m][n];
}