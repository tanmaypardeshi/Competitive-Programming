#include <bits/stdc++.h>
using namespace std;

void combination_sum(int index, vector<int> &v, int target, vector<int> &ds, vector<vector<int>> &answer)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        answer.push_back(ds);
        return;
    }

    for (int i = index; i < v.size(); i++)
    {
        if (i > index && v[i] == v[i - 1])
            continue;
        if (v[i] > target)
            break;
        ds.push_back(v[i]);
        combination_sum(i + 1, v, target - v[i], ds, answer);
        ds.pop_back();
    }
}

int main()
{
    int n, target, index = 0;
    vector<int> v, ds;
    vector<vector<int>> answer;
    cin >> n >> target;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    combination_sum(index, v, target, ds, answer);

    for (auto x : answer)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}