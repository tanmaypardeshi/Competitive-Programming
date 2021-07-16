#include <bits/stdc++.h>
using namespace std;

void print_stack(stack<int> &s)
{
    stack<int> temp = s;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
    return;
}

void insert(stack<int> &s, int temp)
{
    if (s.empty())
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();

    reverse(s);

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

    cout << "Stack is:- ";
    print_stack(s);

    reverse(s);

    cout << "After reverse, stack is:- ";
    print_stack(s);

    return 0;
}