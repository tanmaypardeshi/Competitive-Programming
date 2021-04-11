#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    if (n == 1)
    {
        cout << "1" << endl;
    }
    else if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION" << endl;
    }
    else if (n % 2 == 0)
    {
        for (int i = 2; i <= n; i += 2)
        {
            cout << i << " ";
        }
        for (int j = 1; j <= n - 1; j += 2)
        {
            cout << j << " ";
        }
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
        {
            cout << i << " ";
        }
        for (int j = 2; j <= n - 1; j += 2)
        {
            cout << j << " ";
        }
    }
    return 0;
}