#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define NUM 1000000007

lli power(lli x, lli y)
{
    lli temp;

    if (y == 0)
        return 1;

    temp = power(x, y / 2);

    if (y & 1)
        return x * temp * temp % NUM;
    return temp * temp % NUM;
}

int main()
{
    lli x;
    cin >> x;

    lli answer = power(2, x);

    cout << answer % NUM << endl;

    return 0;
}