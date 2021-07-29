#include <bits/stdc++.h>
using namespace std;

int cntr = 0;

void tower_of_hanoi(int s, int d, int h, int n)
{
    cntr++;

    if (n == 1)
    {
        cout << "Moved plate " << n << " from " << s << " to " << d << endl;
        return;
    }

    tower_of_hanoi(s, h, d, n - 1);

    cout << "Moved plate " << n << " from " << s << " to " << d << endl;

    tower_of_hanoi(h, d, s, n - 1);
}

int main()
{
    int n;

    cout << "Enter number of disks:- ";
    cin >> n;

    tower_of_hanoi(1, 3, 2, n);

    return 0;
}