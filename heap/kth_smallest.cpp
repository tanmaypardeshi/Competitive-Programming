#include <bits/stdc++.h>
using namespace std;

void display(priority_queue<int> pq)
{
    priority_queue<int> temp = pq;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    priority_queue<int> pq;

    vector<int> v;

    int n, k;

    cin >> n;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        pq.push(v[i]);

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    cout << "Element is:- " << pq.top() << endl;

    return 0;
}
