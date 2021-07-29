#include <bits/stdc++.h>
using namespace std;

void generate_parentheses(string op, int open, int close, vector<string> &v)
{
    if (open == 0 && close == 0)
    {
        v.push_back(op);
        return;
    }
    if (open != 0)
    {
        string op1 = op;
        op1.push_back('(');
        generate_parentheses(op1, open - 1, close, v);
    }
    if (close > open)
    {
        string op2 = op;
        op2.push_back(')');
        generate_parentheses(op2, open, close - 1, v);
    }
}

int main()
{
    int n;

    cout << "Enter n:- ";
    cin >> n;

    int open = n;
    int close = n;
    string op = "";
    vector<string> v;

    generate_parentheses(op, open, close, v);

    for (auto x : v)
    {
        cout << x << endl;
    }

    return 0;
}