#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, flag, count = 0;

    cin >> n;

    int *array = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 1; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                flag = 1;
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                count++;
            }
        }
        if (!flag)
            break;
    }
    cout << count << endl;
    return 0;
}