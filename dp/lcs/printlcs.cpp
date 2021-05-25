#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int lcs(string, string, int, int);

int main()
{
    string a;
    string b;

    cin >> a >> b;

    int i = a.length(), j = b.length();
    int index = lcs(a, b, i, j);

    char *answer = new char[index + 1];

    answer[index] = '\0';

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            answer[index - 1] = a[i - 1];
            i--;
            j--;
            index--;
        }
        else if (t[i][j - 1] > t[i - 1][j])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    cout << answer << endl;

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