#include <bits/stdc++.h>
using namespace std;

void n_bit_binary_nos(string op, int ones, int zeroes, int n, vector<string> &v)
{
    if (n == 0)
    {
        v.push_back(op);
        return;
    }
    string op1 = op;
    op1.push_back('1');
    n_bit_binary_nos(op1, ones + 1, zeroes, n - 1, v);

    if (ones > zeroes)
    {
        string op2 = op;
        op2.push_back('0');
        n_bit_binary_nos(op2, ones, zeroes + 1, n - 1, v);
    }
}

int main()
{
    int n;
    int ones, zeroes;
    vector<string> v;
    cout << "Enter n:- ";
    cin >> n;
    string op = "";
    ones = 0;
    zeroes = 0;
    n_bit_binary_nos(op, ones, zeroes, n, v);

    for (auto x : v)
    {
        cout << x << endl;
    }

    return 0;
}