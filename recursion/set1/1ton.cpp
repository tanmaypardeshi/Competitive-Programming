#include <bits/stdc++.h>
using namespace std;

void print1ton(int);

int main()
{
    int n;

    cout << "Enter n:- ";
    cin >> n;

    print1ton(n);

    return 0;
}

void print1ton(int n)
{
    if (n == 1)
    {
        cout << n << endl;
        return;
    }

    print1ton(n - 1);

    cout << n << endl;
}