/* 
Given two sorted arrays, we need to merge them in O((n+m)*log(n+m)) 
time with O(1) extra space into a sorted array, when n is the size 
of the first array, and m is the size of the second array.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a, b, c;

    int m, n;

    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    for (int j = 0; j < n; j++)
    {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }

    while (i < m)
    {
        c.push_back(a[i]);
        i++;
    }

    while (j < n)
    {
        c.push_back(b[j]);
        j++;
    }

    for (auto x : c)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}