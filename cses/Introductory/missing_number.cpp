#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    long int sum1 = 0;
    long int sum2 = 0;
    long int a = 0;
    cin >> n;

    for (long int i = 0; i < n - 1; i++)
    {
        long int temp;
        cin >> temp;
        sum2 += temp;
    }
    for (long int i = 1; i <= n; i++)
    {
        sum1 += i;
    }

    cout << sum1 - sum2 << endl;

    return 0;
}