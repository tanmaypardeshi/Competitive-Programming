#include <bits/stdc++.h>
using namespace std;

typedef struct meeting
{
    int start, end, pos;
} Meeting;

bool compare(Meeting m1, Meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}

void n_meetings(int start[], int end[], int n)
{
    Meeting *m = new Meeting[n];

    for (int i = 0; i < n; i++)
    {
        m[i].start = start[i];
        m[i].end = end[i];
        m[i].pos = i + 1;
    }

    sort(m, m + n, compare);

    vector<int> answer;

    int limit = m[0].end;

    answer.push_back(m[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (m[i].start > limit)
        {
            limit = m[i].end;
            answer.push_back(m[i].pos);
        }
    }

    for (auto x : answer)
    {
        cout << x << " ";
    }

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter n:- ";
    cin >> n;

    int *start = new int[n];
    int *end = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter start[" << i << "]:- ";
        cin >> start[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter end[" << i << "]:- ";
        cin >> end[i];
    }

    n_meetings(start, end, n);
}