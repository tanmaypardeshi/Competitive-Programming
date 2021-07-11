#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int, int>> pq;

    int n, k, x;

    cin >> n >> k >> x;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(abs(arr[i] - x), arr[i]));
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    cout << endl;

    while (!pq.empty())
    {
        cout << pq.top().second << endl;
        pq.pop();
    }
}