#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int lcs(string, string, int, int);

int main()
{
    memset(t, -1, sizeof(t));

    string x, y;

    cin >> x >> y;

    int count = lcs(x, y, x.size(), y.size());

    cout << count << endl;

    return 0;
}

int lcs(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (t[m][n] != -1)
        return t[m][n];

    if (x[m - 1] == y[n - 1])
        return t[m][n] = 1 + lcs(x, y, m - 1, n - 1);
    else
        return t[m][n] = max(lcs(x, y, m - 1, n), lcs(x, y, m, n - 1));
}