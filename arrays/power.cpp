/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

#include <bits/stdc++.h>
using namespace std;

double power(double x, int n)
{
    bool neg = (n < 0);
    n = abs(n);
    double res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res * x);
        x = (x * x);
        n = (n >> 1);
    }
    if (neg)
        res = 1 / res;
    return res;
}

int main()
{
    double x;
    int n;

    cin >> x >> n;

    double ans = power(x, n);

    cout << ans << endl;

    return 0;
}