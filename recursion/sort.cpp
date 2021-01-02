#include <bits/stdc++.h>
using namespace std;

void sort(vector<int> &);
void insert(vector<int> &, int);

int main()
{
    int n, temp;
    vector<int> v;

    cout << "Enter n:- ";
    cin >> n;

    cout << "Enter elements in the array:- ";

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v);

    for (auto x : v)
    {
        cout << x << endl;
    }

    return 0;
}

void sort(vector<int> &v)
{
    if (v.size() == 1)
    {
        return;
    }

    int temp = v[v.size() - 1];
    v.pop_back();

    sort(v);

    insert(v, temp);
}

void insert(vector<int> &v, int val)
{
    if (v.size() == 0 || v[v.size() - 1] <= val)
    {
        v.push_back(val);
        return;
    }

    int temp = v[v.size() - 1];
    v.pop_back();

    insert(v, val);

    v.push_back(temp);

    return;
}