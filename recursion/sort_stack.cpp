#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp)
{
    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
    return;
}

void sort_stack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();
    sort_stack(s);
    insert(s, temp);
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

    sort_stack(s);

    cout << "Sorted stack is:- " << endl;

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}