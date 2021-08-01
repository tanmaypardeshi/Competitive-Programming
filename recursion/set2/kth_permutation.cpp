#include <bits/stdc++.h>
using namespace std;

string kth_permutation(int n, int k)
{
    int fact = 1;
    vector<int> numbers;
    string ans = "";

    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k = k - 1;
    while (true)
    {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
        {
            return ans;
        }
        k = k % fact;
        fact = fact / numbers.size();
    }
}

int main()
{
    int n, k;

    cin >> n >> k;

    string ans = kth_permutation(n, k);

    cout << ans << endl;

    return 0;
}