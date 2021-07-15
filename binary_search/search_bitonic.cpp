#include <bits/stdc++.h>
using namespace std;

int binary_search_asc(vector<int> v, int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (v[mid] == key)
        {
            return v[mid];
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
    return -1;
}

int binary_search_desc(vector<int> v, int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (v[mid] == key)
        {
            return v[mid];
        }
        else if (key < v[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int find_peak_index(vector<int> v, int left, int right)
{
    int size = v.size();

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid > 0 && mid < size - 1)
        {
            if (v[mid] > v[mid + 1] && v[mid] > v[mid - 1])
            {
                return mid;
            }
            else if (v[mid] > v[mid - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else if (mid == 0)
        {
            if (v[mid] > v[mid + 1])
            {
                return mid;
            }
            else
            {
                return mid + 1;
            }
        }
        else if (mid == size - 1)
        {
            if (v[mid] > v[mid - 1])
            {
                return mid;
            }
            else
            {
                return mid - 1;
            }
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

    int key;

    cout << "Enter key:- ";
    cin >> key;

    int index = find_peak_index(v, 0, v.size());

    cout << "Index of peak element = " << index << endl;

    int answer = binary_search_asc(v, 0, index - 1, key);
    if (answer == -1)
    {
        answer = binary_search_desc(v, index, v.size() - 1, key);
    }

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