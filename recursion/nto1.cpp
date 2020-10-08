#include<bits/stdc++.h>
using namespace std;

void print(int);

int main()
{
    int n;

    cout<<"Enter n:- ";
    cin>>n;

    print(n);

}

void print(int n)
{
    if(n == 1)
    {
        cout<<n<<endl;
        return;
    }
    cout<<n<<endl;
    print(n-1);

}