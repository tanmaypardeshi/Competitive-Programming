#include <bits/stdc++.h>
using namespace std;

void display(priority_queue<int, vector<int>, greater<int>> pq)
{
    priority_queue<int, vector<int>, greater<int>> temp = pq;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter an element:- ";
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    cout << endl;
    cout << "Heap is:- ";
    display(pq);
    cout << endl;

    cout << "Top is:- " << pq.top() << endl;
    cout << "Size is:- " << pq.size() << endl;

    return 0;
}