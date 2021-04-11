#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        long long int x, y, value;

        cin >> x >> y;

        if (x >= y)
        {
            if (x % 2 == 0)
                value = (x * x) - y + 1;
            else
                value = ((x - 1) * (x - 1)) + y;
        }
        else
        {
            if (y % 2 != 0)
                value = (y * y) - x + 1;
            else
                value = ((y - 1) * (y - 1)) + x;
        }
        cout << value << endl;
    }
    return 0;
}