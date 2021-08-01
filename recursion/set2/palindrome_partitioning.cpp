#include <bits/stdc++.h>
using namespace std;

void solve(int index, string s, vector<string> &path, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(path);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            solve(i + 1, s, path, res);
            path.pop_back();
        }
    }
}

bool isPalindrome(string s, int l, int r)
{
    while (l <= r)
    {
        if (s[l++] != s[r--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;

    cin >> s;

    vector<vector<string>> res;
    vector<string> path;
    int index = 0;
    solve(index, s, path, res);

    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}