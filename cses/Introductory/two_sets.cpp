#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long int sum = 0;
    int *array = new int[n];

    for (int i = 0; i < n; i++)
    {
        int temp = array[i];
        cin >> temp;
        sum += temp;
    }
    if (sum % 2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        if (n % 2 == 0)
        {
        }
    }
}