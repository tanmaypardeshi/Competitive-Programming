#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

void subset_sum(vector<int> ip, vector<int> op)
{
    if (ip.size() == 0)
    {
        int sum = 0;
        for (auto x : op)
        {
            sum += x;
        }
        answer.push_back(sum);
        return;
    }

    vector<int> op1 = op;
    vector<int> op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

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