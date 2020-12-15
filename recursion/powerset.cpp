#include <bits/stdc++.h>
using namespace std;

void solve(string, string);

int main()
{
    string ip = "";
    string op = "";

    cout << "Enter string:- ";
    cin >> ip;

    solve(ip, op);

    return 0;
}

void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }
    cout << op << endl;
    string op1 = op;
    string op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    solve(ip, op1);
    solve(ip, op2);
}