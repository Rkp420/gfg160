#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumProfit(vector<int> &prices)
    {
        // code here
        int mini = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < mini)
                mini = prices[i];
            else
            {
                maxProfit = max(maxProfit, prices[i] - mini);
            }
        }

        return maxProfit;
    }
};

int main()
{
    return 0;
}