#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> v, int left, int right, int key)
{
    int res = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (v[mid] == key)
        {
            return v[mid];
        }

        else if (v[mid] < key)
        {
            res = v[mid];
            left = mid + 1;
        }

        else if (v[mid] > key)
        {
            right = mid - 1;
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

    int answer = binary_search(v, 0, v.size() - 1, key);

    if (answer != -1)
    {
        cout << key << " is the floor of " << answer << endl;
    }
    else
    {
        cout << "Floor not found in array" << endl;
    }
}