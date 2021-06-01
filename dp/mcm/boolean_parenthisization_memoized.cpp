#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int solve(string, int, int, bool);

int main()
{
    mp.clear();
    string a;
    int i, j;

    cin >> a;

    i = 0;
    j = a.length() - 1;

    int ans = solve(a, i, j, true);

    cout << ans << endl;

    return 0;
}

int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;

    if (i == j)
    {
        if (isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    string temp = to_string(i);
    temp.append(" ");
    temp.append(to_string(j));
    temp.append(" ");
    temp.append(to_string(isTrue));

    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue == true)
                ans += lt * rt;
            else
                ans += lf * rf + lf * rt + lt * rf;
        }
        else if (s[k] == '|')
        {
            if (isTrue == true)
                ans += lt * rf + lf * rt + lt * rt;
            else
                ans += lf * rf;
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
                ans += lt * rf + rt * lf;
            else
                ans += lt * rt + lf * rf;
        }
    }

    return mp[temp] = ans;
}