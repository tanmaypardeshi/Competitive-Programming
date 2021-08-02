#include <bits/stdc++.h>
#define V 4
using namespace std;

bool isSafe(int node, int color[], bool graph[V][V], int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == true && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[V][V])
{
    if (node == N)
    {
        return true;
    }

    for (int i = 0; i < m; i++)
    {
        if (isSafe(node, color, graph, N, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, N, graph))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

int main()
{
    // Driver code here

    return 0;
}