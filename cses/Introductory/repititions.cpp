#include <bits/stdc++.h>
using namespace std;

int main()
{
    int best = 0, current = 1;
    string s;
    cin >> s;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            best = max(best, current);
            current = 0;
        }
        current++;
    }

    best = max(best, current);

    cout << best;

    return 0;
}