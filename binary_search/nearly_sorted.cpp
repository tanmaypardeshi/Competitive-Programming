#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> v, int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (v[mid] == key)
        {
            return v[mid];
        }
        else if (mid - 1 >= left && v[mid - 1] == key)
        {
            return v[mid - 1];
        }
        else if (mid + 1 <= right && v[mid + 1] == key)
        {
            return v[mid + 1];
        }

        else if (v[mid] <= key)
        {
            left = mid + 2;
        }
        else if (v[mid] >= key)
        {
            right = mid - 2;
        }
    }
    return -1;
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
        cout << key << " is present in array" << endl;
    }
    else
    {
        cout << key << " not found in array" << endl;
    }

    return 0;
}