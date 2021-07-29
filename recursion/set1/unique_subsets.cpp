#include <bits/stdc++.h>
using namespace std;

void print_unique_subsets(string ip, string op, set<string> &answer)
{
    if (ip.length() == 0)
    {
        answer.insert(op);
        return;
    }

    string op1 = op;
    string op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    print_unique_subsets(ip, op1, answer);
    print_unique_subsets(ip, op2, answer);
}

int main()
{
    string s;
    cout << "Enter a string:- ";
    cin >> s;

    set<string> answer;

    print_unique_subsets(s, "", answer);

    for (auto x : answer)
    {
        cout << x << endl;
    }

    return 0;
}