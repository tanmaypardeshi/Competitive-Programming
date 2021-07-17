#include <bits/stdc++.h>
using namespace std;

void case_change(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.push_back(ip[0]);
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin() + 0);

    case_change(ip, op1);
    case_change(ip, op2);
}

int main()
{
    string s;
    cout << "Enter a string:- ";
    cin >> s;
    string op = "";
    case_change(s, op);

    return 0;
}