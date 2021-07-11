#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;

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

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto x : mp)
    {
        pq.push(make_pair(x.second, x.first));

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    cout << endl;

    while (!pq.empty())
    {
        cout << pq.top().second << " " << pq.top().first << endl;
        pq.pop();
    }

    cout << endl;

    return 0;
}