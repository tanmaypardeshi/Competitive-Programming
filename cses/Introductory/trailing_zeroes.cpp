#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli num;

    cin >> num;
    int mult = 5, count = 0;
    while (num / mult >= 1)
    {
        count += int(num / mult);
        mult *= 5;
    }
    cout << count << endl;
    return 0;
}
