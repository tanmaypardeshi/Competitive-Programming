#include <bits/stdc++.h>
using namespace std;

void permutations_with_spaces(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.append("_");
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    permutations_with_spaces(ip, op1);
    permutations_with_spaces(ip, op2);
}

int main()
{
    string s;
    cout << "Enter a string:- ";
    cin >> s;
    string op = "";
    op.append(1, s[0]);
    s.erase(s.begin() + 0);
    permutations_with_spaces(s, op);

    return 0;
}