#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> v, int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (v[mid] == key)
        {
            return 0;
        }
        else if (v[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return min(abs(v[left] - key), abs(v[right] - key));
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

    cout << "Minumum difference = " << answer << endl;
    return 0;
}