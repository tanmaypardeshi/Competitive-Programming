#include <bits/stdc++.h>
using namespace std;

void letter_case(string ip, string op, vector<string> &v)
{
    if (ip.length() == 0)
    {
        v.push_back(op);
        return;
    }

    if (isalpha(ip[0]))
    {
        string op1 = op;
        string op2 = op;

        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));

        ip.erase(ip.begin() + 0);

        letter_case(ip, op1, v);
        letter_case(ip, op2, v);
    }
    else
    {
        string op1 = op;

        op1.push_back(ip[0]);

        ip.erase(ip.begin() + 0);

        letter_case(ip, op1, v);
    }
}

int main()
{
    string s;
    vector<string> v;
    cout << "Enter a string:- ";
    cin >> s;
    string op = "";
    letter_case(s, op, v);

    for (auto x : v)
    {
        cout << x << endl;
    }

    return 0;
}