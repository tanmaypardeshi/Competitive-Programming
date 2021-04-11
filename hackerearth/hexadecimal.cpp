#include <bits/stdc++.h>
using namespace std;

int hex(int number)
{
    int sum = 0;

    while (number > 0)
    {
        sum += number % 16;
        number /= 16;
    }
    return sum;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return (b, a % b);
}

int main()
{
    int t;
    int l, r;

    cin >> t;

    while (t > 0)
    {
        int count = 0;
        cin >> l >> r;
        for (int i = l; i <= r; i++)
        {
            if (gcd(i, hex(i)) > 1)
                count++;
        }
        cout << count << endl;
        t--;
    }
    return 0;
}