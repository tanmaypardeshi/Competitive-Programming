#include <bits/stdc++.h>
using namespace std;

bool is_valid(vector<int> v, int n, int k, int mid)
{
    int sum = 0;
    int student = 1;

    for (int i = 0; i < n; i++)
    {
        sum += v[i];

        if (sum > mid)
        {
            student++;
            sum = v[i];
        }
    }

    if (student > k)
    {
        return false;
    }
    return true;
}

int main()
{
    vector<int> v;
    int n, k;

    cout << "Enter size of array:- ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cout << "Enter arr[" << i << "]:- ";
        cin >> temp;
        v.push_back(temp);
    }

    cout << "Enter number of students:- ";
    cin >> k;

    if (n < k)
    {
        cout << "Invalid" << endl;
        return 0;
    }
    int left = INT_MIN;
    int right = accumulate(v.begin(), v.end(), 0);
    int res = -1;

    for (int i = 0; i < n; i++)
    {
        if (v[i] > left)
            left = v[i];
    }

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (is_valid(v, n, k, mid))
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << "Minimum number of pages:- " << res << endl;
}