#include <bits/stdc++.h>
using namespace std;

char binary_search(string s, int left, int right, char key)
{
    char res = '\0';
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (s[mid] == key)
        {
            left = mid + 1;
        }
        if (s[mid] < key)
        {
            left = mid + 1;
        }
        else if (s[mid] > key)
        {
            res = s[mid];
            right = mid - 1;
        }
    }

    return res;
}

int main()
{
    string s;
    cout << "Enter a string:- ";
    cin >> s;

    sort(s.begin(), s.end());

    char key;

    cout << "Enter key:- ";
    cin >> key;

    char next = binary_search(s, 0, s.size() - 1, key);

    if (next != '\0')
    {
        cout << key << " is the next alphabet of " << next << endl;
    }
    else
    {
        cout << "Floor not found in array" << endl;
    }
}