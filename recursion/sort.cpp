#include<bits/stdc++.h>
using namespace std;


void sort(vector<int> &);
void insert(vector<int> &, int);

int main()
{
    vector<int> v;

    int n, num;

    cout<<"Enter size of array:- ";

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>num;
        v.push_back(num);
    }

    sort(v);

    for(auto x:v)
        cout<<x<<"\t";
    cout<<endl;

    return 0;
}

void sort(vector<int> & v)
{
    if(v.size() == 1)
        return;

    int temp = v[v.size() - 1];
    v.pop_back();

    sort(v);

    insert(v, temp);
}

void insert(vector<int> & v, int temp)
{
    if(v.size() == 0 || v[v.size() -1 ] <= temp)
    {
        v.push_back(temp);
        return;
    }

    int val = v[v.size() -1];
    v.pop_back();

    insert(v, temp);

    v.push_back(val);

    return;
}