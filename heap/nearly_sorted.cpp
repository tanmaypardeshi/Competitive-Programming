#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int n, k;
    int index = 0;

    cin >> n;
    cin >> k;

    int *v = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < k + 1; i++)
    {
        pq.push(v[i]);
    }

    for (int i = k + 1; i < n; i++)
    {
        v[index++] = pq.top();
        pq.pop();
    }

    while (!pq.empty())
    {
        v[index++] = pq.top();
        pq.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}