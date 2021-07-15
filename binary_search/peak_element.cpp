#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> v, int left, int right)
{
    int size = v.size();
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mid > 0 && mid < size - 1)
        {
            if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
            {
                return v[mid];
            }
            else if (v[mid] < v[mid - 1])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if (mid == 0)
        {
            if (v[mid] > v[mid + 1])
            {
                return v[mid];
            }
            else
            {
                return v[mid + 1];
            }
        }
        else if (mid == size - 1)
        {
            if (v[mid] > v[mid - 1])
            {
                return v[mid];
            }
            else
            {
                return v[mid - 1];
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

    int answer = binary_search(v, 0, v.size() - 1);

    cout << "Peak element is:- " << answer << endl;

    return 0;
}