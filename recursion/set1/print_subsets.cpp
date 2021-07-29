#include <bits/stdc++.h>
using namespace std;

void print_subsets(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    print_subsets(ip, op1);
    print_subsets(ip, op2);
}

int main()
{
    string s;

    cout << "Enter a string:- ";
    cin >> s;

    print_subsets(s, "");

    return 0;
}