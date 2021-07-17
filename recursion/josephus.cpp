#include <bits/stdc++.h>
using namespace std;

void josephus(vector<int> &v, int index, int k, int &answer)
{
    if (v.size() == 1)
    {
        answer = v[0];
        return;
    }
    index = (index + k) % v.size();

    v.erase(v.begin() + index);

    josephus(v, index, k, answer);
}

int main()
{
    int n, k;

    cout << "Enter total number of people:- ";
    cin >> n;

    cout << "Enter counter:- ";
    cin >> k;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back(i + 1);
    }
    int index = 0;
    int answer = -1;
    josephus(v, 0, k - 1, answer);

    cout << "Person who is saved is at position " << answer << endl;

    return 0;
}