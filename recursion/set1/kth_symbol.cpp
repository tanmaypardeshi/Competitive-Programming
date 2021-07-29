#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{
    if (n == 1 && k == 1)
    {
        return 0;
    }
    int mid = pow(2, n - 2);

    if (k <= mid)
    {
        return solve(n - 1, k);
    }
    else
    {
        return !solve(n - 1, k - mid);
    }
}

int main()
{
    int n, k;

    cout << "Enter n:- ";
    cin >> n;

    cout << "Enter k:- ";
    cin >> k;

    int answer = solve(n, k);

    cout << "Answer is:- " << answer << endl;

    return 0;
}