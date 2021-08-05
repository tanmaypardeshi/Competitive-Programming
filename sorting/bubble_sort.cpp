#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr)
{
    int n = arr.size(), flag;

    for (int i = 1; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

int main()
{
    int n;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    bubble_sort(v);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}