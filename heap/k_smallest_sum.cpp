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

int get_kth_smallest(vector<int> v, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top();
}

int main()
{

    vector<int> v;

    int n, k1, k2, sum = 0;

    cin >> n;
    cin >> k1;
    cin >> k2;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        v.push_back(temp);
    }

    int first = get_kth_smallest(v, k1);
    int second = get_kth_smallest(v, k2);

    for (int i = 0; i < n; i++)
    {
        if (v[i] > first && v[i] < second)
        {
            sum += v[i];
        }
    }

    cout << sum << endl;

    return 0;
}
