#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int, pair<int, int>>> pq;
    int rows, k;

    cin >> rows >> k;

    int **arr = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[2];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        int pr = arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1];
        pq.push(make_pair(pr, make_pair(arr[i][0], arr[i][1])));
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    cout << endl;

    while (!pq.empty())
    {
        cout << "x:- " << pq.top().second.first << ", y:- " << pq.top().second.second << ", distance:- " << pq.top().first << endl;
        pq.pop();
    }

    cout << endl;

    return 0;
}