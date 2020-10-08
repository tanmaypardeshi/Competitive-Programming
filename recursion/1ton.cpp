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
    print(n-1);
    cout<<n<<endl;
}