#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int minprice = INT_MAX;
    int maxprofit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < minprice)
            minprice = prices[i];
        else if (prices[i] - minprice > maxprofit)
            maxprofit = prices[i] - minprice;
    }
    return maxprofit;
}

int main()
{
    int n;
    cin >> n;

    vector<int> prices;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        prices.push_back(temp);
    }

    int ans = maxProfit(prices);

    return ans;
}