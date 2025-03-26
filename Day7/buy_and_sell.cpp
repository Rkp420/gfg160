#include <iostream>
using namespace std;

// Recursive approach
#include <iostream>
#include <vector>
using namespace std;

int maxProfitRec(vector<int> &price, int start, int end)
{
    int res = 0;

    // Consider every valid pair, find the profit with it
    // and recursively find profits on left and right of it
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (price[j] > price[i])
            {
                int curr = (price[j] - price[i]) +
                           maxProfitRec(price, start, i - 1) +
                           maxProfitRec(price, j + 1, end);
                res = max(res, curr);
            }
        }
    }
    return res;
}

// Wrapper function
int maximumProfit(vector<int> &prices)
{
    return maxProfitRec(prices, 0, prices.size() - 1);
}

// Better Approach

class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        // code here
        int n = prices.size();
        if (n == 1)
            return 0;

        int buy = -1;
        int sell = -1;
        int res = 0;

        int i = 0;
        while (i < n - 1)
        {
            while (i < n - 1 && prices[i] >= prices[i + 1])
                i++;
            buy = i;

            while (i < n - 1 && prices[i] <= prices[i + 1])
                i++;
            sell = i;

            res = res + (prices[sell] - prices[buy]);
        }

        return res;
    }
};

// More Better Approach

class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        // code here
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                res += (prices[i] - prices[i - 1]);
        }

        return res;
    }
};

int main()
{
    return 0;
}