#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

void subset_sum(vector<int> &ip, vector<int> &op)
{
    if (ip.size() == 0)
    {
        int sum = 0;
        for (auto x : op)
        {
            sum += x;
        }
        answer.push_back(sum);
    }

    vector<int> op1 = op;
    vector<int> op2 = op;

    op1.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    cout << "op1 ";
    for (auto x : op1)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "op2 ";
    for (auto x : op2)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "ip ";
    for (auto x : ip)
    {
        cout << x << " ";
    }
    cout << endl;

    subset_sum(ip, op1);
    subset_sum(ip, op2);
}

int main()
{
    vector<int> ip, op;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ip.push_back(temp);
    }

    subset_sum(ip, op);

    sort(answer.begin(), answer.end());

    for (auto x : answer)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}