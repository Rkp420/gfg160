#include <iostream>
using namespace std;

class Solution
{
public:
    int maxSubarraySum(vector<int> &arr)
    {
        // Your code here
        int maxSum = 0;
        int max_neg_ele = INT_MIN;
        // Next
        int currSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            currSum += arr[i];
            if (currSum < 0)
            {
                currSum = 0;
            }
            else
            {
                maxSum = max(maxSum, currSum);
            }

            max_neg_ele = max(max_neg_ele, arr[i]);
        }

        return maxSum == 0 ? max_neg_ele : maxSum;
    }
};

int main()
{
    return 0;
}