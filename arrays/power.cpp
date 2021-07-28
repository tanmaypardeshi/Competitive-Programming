/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

#include <bits/stdc++.h>
using namespace std;

double power_itr(double x, int n)
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

double power_rec(double x, int n)
{
    if (n == 0)
        return 1;
    int temp = power_rec(x, n / 2);
    int result = temp * temp;
    if (n % 2 == 1)
        result *= x;
    return result;
}

int main()
{
    double x;
    int n;

    cin >> x >> n;

    double ans1 = power_itr(x, n);

    double ans2 = power_rec(x, n);

    cout << ans1 << endl;
    cout << ans2 << endl;

    return 0;
}