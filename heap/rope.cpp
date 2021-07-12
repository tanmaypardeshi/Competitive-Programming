#include <bits/stdc++.h>
using namespace std;

void display(priority_queue<int, vector<int>, greater<int>> pq)
{
    priority_queue<int, vector<int>, greater<int>> temp = pq;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    int n, cost = 0;

    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    display(pq);

    while (pq.size() >= 2)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        cost = cost + first + second;

        pq.push(first + second);
    }

    cout << cost << endl;

    return 0;
}