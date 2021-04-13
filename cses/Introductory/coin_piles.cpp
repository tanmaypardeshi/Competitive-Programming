#include <iostream>
using namespace std;

int main()
{
    long long int t, a, b;
    cin >> t;
    while (t > 0)
    {
        cin >> a >> b;
        cout << ((a + b) % 3 == 0 && (min(a, b) * 2 >= max(a, b)) ? "YES" : "NO") << endl;
        t--;
    }
    return 0;
}
// int main()
// {
//     int t;

//     cin >> t;

//     while (t > 0)
//     {
//         int a, b;

//         cin >> a >> b;
//         while (a > 0 && b > 0)
//         {
//             if (a > b)
//             {
//                 a -= 2;
//                 b -= 1;
//             }
//             else
//             {
//                 a -= 1;
//                 b -= 2;
//             }
//         }
//         if (a == 0 && b == 0)
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//         t--;
//     }
//     return 0;
// }