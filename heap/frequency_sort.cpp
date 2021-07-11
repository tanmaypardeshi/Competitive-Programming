#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;

    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    priority_queue<pair<int, int>> pq;

    for (auto x : mp)
    {
        pq.push(make_pair(x.second, x.first));
    }

    cout << endl;

    while (!pq.empty())
    {
        int freq = pq.top().first;
        int num = pq.top().second;

        for (int i = 0; i < freq; i++)
        {
            cout << num << " ";
        }
        pq.pop();
    }

    cout << endl;

    return 0;
}