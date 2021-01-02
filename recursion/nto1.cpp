#include <bits/stdc++.h>
using namespace std;

void printnto1(int);

int main()
{
    int n;

    cout << "Enter n:- ";
    cin >> n;

    printnto1(n);

    return 0;
}

void printnto1(int n)
{
    if (n == 1)
    {
        cout << n << endl;
        return;
    }

    cout << n << endl;

    printnto1(n - 1);
}
