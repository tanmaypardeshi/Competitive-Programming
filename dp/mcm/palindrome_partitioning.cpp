#include <bits/stdc++.h>
using namespace std;

int solve(string, int, int);
bool isPalindrome(string, int, int);

int main()
{
    string s;

    cin >> s;

    int i = 0;
    int j = s.length() - 1;

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

    int mn = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;

        mn = min(temp, mn);
    }

    return mn;
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