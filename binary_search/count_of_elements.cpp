#include <bits/stdc++.h>
using namespace std;

int first_occurence(vector<int> v, int left, int right, int key)
{
    int res = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (key == v[mid])
        {
            res = mid;
            right = mid - 1;
        }
        else if (key < v[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return res;
}

int last_occurence(vector<int> v, int left, int right, int key)
{
    int res = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (key == v[mid])
        {
            res = mid;
            left = mid + 1;
        }
        else if (key < v[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return res;
}

int main()
{
    vector<int> v;

    int n;
    cout << "Enter size:- ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cout << "Enter arr[" << i << "]:- ";
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int key;

    cout << "Enter key:- ";
    cin >> key;

    int first = first_occurence(v, 0, v.size() - 1, key);
    int last = last_occurence(v, 0, v.size() - 1, key);

    cout << "Total count of " << key << " in the array is:- " << last - first + 1 << endl;

    return 0;
}