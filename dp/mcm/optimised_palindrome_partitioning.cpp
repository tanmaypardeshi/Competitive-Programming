#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
int solve(string, int, int);
bool isPalindrome(string, int, int);

int main()
{
    string s;

    cin >> s;

    int i = 0;
    int j = s.length() - 1;

    memset(t, -1, sizeof(t));

    int ans = solve(s, i, j);

    cout << ans << endl;

    return 0;
}

int solve(string s, int i, int j)
{
    if (i >= j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int mn = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int left, right;

        if (t[i][k] != -1)
            left = t[i][k];
        else
            left = solve(s, i, k);

        if (t[k + 1][j] != -1)
            right = t[k + 1][j];
        else
            right = solve(s, k + 1, j);
        int temp = left + right + 1;

        mn = min(mn, temp);
    }

    return t[i][j] = mn;
}

bool isPalindrome(string s, int i, int j)
{
    if (i == j)
        return true;
    if (i > j)
        return true;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }

    return true;
}