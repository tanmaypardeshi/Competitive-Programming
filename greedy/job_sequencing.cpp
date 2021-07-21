#include <bits/stdc++.h>
using namespace std;

typedef struct job
{
    int id, deadline, profit;
} Job;

bool compare(Job j1, Job j2)
{
    if (j1.profit > j2.profit)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cout << "Enter n:- ";
    cin >> n;

    Job *job = new Job[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter id[" << i << "]:- ";
        cin >> job[i].id;
        cout << "Enter deadline[" << i << "]:- ";
        cin >> job[i].deadline;
        cout << "Enter profit[" << i << "]:- ";
        cin >> job[i].profit;
    }

    sort(job, job + n, compare);

    int *result = new int[n];
    bool *slot = new bool[n];

    for (int i = 0; i < n; i++)
    {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, job[i].deadline) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    cout << "\nJob ids are:- ";
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
            cout << result[i] << " ";
    }

    cout << endl;
}