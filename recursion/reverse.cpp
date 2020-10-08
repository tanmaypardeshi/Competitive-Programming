#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &, int);
void reverse(stack<int> &);

int main()
{
    stack<int> s;

    int n, num;

    cout<<"Enter number of elements:- ";
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cout<<"Enter element "<<i+1<<":- ";
        cin>>num;
        s.push(num);
    }
    if(s.empty())
    {
        cout<<"Stack underflow"<<endl;
        return 0;
    }
    int k = s.size()/2 + 1;

    reverse(s);

    cout<<"New stack is:- "<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<"\t";
        s.pop();
    }

    cout<<endl;
    return 0;
}

void insert(stack<int> & s, int element)
{
    if(s.size() == 0)
    {
        s.push(element);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(s, element);

    s.push(temp);

    return;
}

void reverse(stack<int> &s)
{
    if(s.size() == 1)
    {
        return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s, temp);

    return;
}