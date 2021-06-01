/*
Given an unsorted array of size n. 
Array elements are in the range from 1 to n. 
One number from set {1, 2, …n} is missing and one number occurs twice in the array. 
Find these two numbers.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;

    cin >> n;

    int *arr = new int[n + 1];

    memset(arr, 0, sizeof(arr));

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    int miss, rep;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 2)
            rep = i;
        if (arr[i] == 0)
            miss = i;
    }
    cout << rep << " " << miss << endl;
    return 0;
}