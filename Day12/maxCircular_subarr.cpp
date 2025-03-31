#include <iostream>
using namespace std;

// BruteForce

class Solution
{
public:
    int circularSubarraySum(vector<int> &arr)
    {

        int n = arr.size();
        if (n == 1)
            return arr[0];

        // BruteForce : O(n * n)
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int currSum = 0;
            for (int j = 0; j < n; j++)
            {
                int idx = (j + i) % n;

                currSum += arr[idx];

                ans = max(ans, currSum);
            }
        }

        return ans;
    }
};

// Using Prefix and Suffix Sum

class Solution
{
public:
    int circularSubarraySum(vector<int> &arr)
    {

        int n = arr.size();
        if (n == 1)
            return arr[0];

        // Using Prefix & Suffix Sum Approach => T.c : O(n)
        //                                    => S.c : O(n)

        // Step 1 : Creating SuffixSum Array
        vector<int> suffixSum(n + 1, 0);
        suffixSum[n - 1] = arr[n - 1];

        int currSuffSum = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            currSuffSum += arr[i];

            suffixSum[i] = max(suffixSum[i + 1], currSuffSum);
        }

        // Step-2 : Time To Calculate Ans and Together We Compute PrefixSum;

        int circularSum = arr[0];
        int normalSum = arr[0];

        int prefSum = 0;
        int currSum = 0;

        for (int i = 0; i < n; i++)
        {

            // Kadan's For Normal Sum
            currSum = max(currSum + arr[i], arr[i]);
            normalSum = max(normalSum, currSum);

            // Approach For Circular Sum

            prefSum = prefSum + arr[i];

            circularSum = max(circularSum, prefSum + suffixSum[i + 1]);
        }

        return max(circularSum, normalSum);
    }
};

// Using Kadan's Algorithm

class Solution
{
public:
    int circularSubarraySum(vector<int> &arr)
    {

        int n = arr.size();
        if (n == 1)
            return arr[0];

        // Approach : CircularSum = TotalSum - MinSubarraySum

        int minSum = INT_MAX;
        int maxSum = INT_MIN;

        int currMaxSum = 0;
        int currMinSum = 0;

        int totalSum = 0;

        for (int i = 0; i < n; i++)
        {

            // Kadan' Algo For MaxSum;
            currMaxSum = max(currMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currMaxSum);

            // Kadan's Algo For MinSum;
            currMinSum = min(currMinSum + arr[i], arr[i]);
            minSum = min(minSum, currMinSum);

            totalSum += arr[i];
        }

        int circularSum = totalSum - minSum;

        if (totalSum == minSum)
            return maxSum;

        return max(maxSum, circularSum);
    }
};

int main()
{
    return 0;
}