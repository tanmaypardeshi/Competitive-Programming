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

void subset_sum_optimised(int index, int sum, vector<int> &arr, int N, vector<int> &final)
{
    if (index == N)
    {
        final.push_back(sum);
        return;
    }

    subset_sum_optimised(index + 1, sum + arr[index], arr, N, final);
    subset_sum_optimised(index + 1, sum, arr, N, final);
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

    int sum = 0;
    int index = 0;
    vector<int> final;

    subset_sum_optimised(index, sum, ip, n, final);

    sort(final.begin(), final.end());
    for (auto x : final)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}