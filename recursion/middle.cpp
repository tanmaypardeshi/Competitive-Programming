#include <bits/stdc++.h>
using namespace std;

void delete_middle(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();
    delete_middle(s, k - 1);
    s.push(temp);
    return;
}

int main()
{
    stack<int> s;
    int n;

    cout << "Enter size of stack:- ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cout << "Enter element " << i << ":- ";
        cin >> temp;
        s.push(temp);
    }

    int k = s.size() / 2 + 1;

    delete_middle(s, k);

    cout << "Stack after deletion is:- " << endl;

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}