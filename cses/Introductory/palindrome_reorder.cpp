#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int freq[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 65]++;
    }

    int count = 0;

    for (int i = 0; i < 26; i++)
    {
        if (count > 2)
        {
            cout << "NO SOLUTION" << endl;
            break;
        }
        if (freq[i] == 1)
        {
            count++;
        }
    }
    return 0;
}