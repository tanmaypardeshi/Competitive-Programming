#include <bits/stdc++.h>
using namespace std;

int t[1000][1000];
int lcs(string, string, int, int);

int main()
{
    string a, b, answer = "";
    int i, j, lc;

    cin >> a >> b;

    i = a.length();
    j = b.length();

    lc = lcs(a, b, i, j);

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            answer.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (t[i - 1][j] > t[i][j - 1])
        {
            answer.push_back(a[i - 1]);
            i--;
        }
        else
        {
            answer.push_back(b[j - 1]);
            j--;
        }
    }

    while (i > 0)
    {
        answer.push_back(a[i - 1]);
        i--;
    }

    while (j > 0)
    {
        answer.push_back(b[j - 1]);
        j--;
    }
    reverse(answer.begin(), answer.end());
    cout << answer << endl;
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