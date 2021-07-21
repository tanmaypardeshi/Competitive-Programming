#include <bits/stdc++.h>
using namespace std;

int deno[] = {1, 2, 5, 10, 20,
              50, 100, 500, 1000};
int deno_size = sizeof(deno) / sizeof(deno[0]);

void min_coins(int n)
{
    vector<int> ans;
    sort(deno, deno + deno_size);

    for (int i = deno_size - 1; i >= 0; i--)
    {
        while (n >= deno[i])
        {
            n -= deno[i];
            ans.push_back(deno[i]);
        }
    }
    cout << "Denominations needed are:- ";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter n:- ";
    cin >> n;
    min_coins(n);
    return 0;
}