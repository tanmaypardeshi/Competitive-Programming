#include<iostream>
#include<stack>
using namespace std;

void middle(stack<int> &, int);

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

    middle(s, k);

    cout<<"New stack is:- "<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<"\t";
        s.pop();
    }

    cout<<endl;
    return 0;
}

void middle(stack<int> & s, int k)
{
    if(k == 1)
    {
        s.pop();
        return;
    }

    int val = s.top();
    s.pop();

    middle(s, k-1);

    s.push(val);

    return;
}
