#include <iostream>
using namespace std;

// BruteForce

class Solution
{
public:
    int findEquilibrium(vector<int> &arr)
    {
        // Bruteforce
        int n = arr.size();

        int leftSum = 0;
        for (int i = 0; i < n; i++)
        {
            int rightSum = 0;
            for (int j = i + 1; j < n; j++)
                rightSum += arr[j];

            if (leftSum == rightSum)
                return i;

            leftSum += arr[i];
        }

        return -1;
    }
};

// Using Prefix Sum

class Solution
{
public:
    int findEquilibrium(vector<int> &arr)
    {
        // Bruteforce
        int n = arr.size();

        vector<int> rightSum(n, 0);

        for (int i = n - 2; i >= 0; i--)
            rightSum[i] = rightSum[i + 1] + arr[i + 1];

        int leftSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (leftSum == rightSum[i])
                return i;
            leftSum += arr[i];
        }

        return -1;
    }
};

int main()
{
    return 0;
}