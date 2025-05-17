#include <iostream>
using namespace std;

// Prefix and Suffix Max Approach

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        // BruteForce
        int n = arr.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        // Filling LeftMax Array
        for (int i = 1; i < n; i++)
            leftMax[i] = max(arr[i - 1], leftMax[i - 1]);

        // Filling RightMax Array
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(arr[i + 1], rightMax[i + 1]);

        // Now it's Time to Calculate Trap Water = min(leftMax[i] - rightMax[i]) - arr[i];
        int trapWater = 0;
        for (int i = 1; i < n; i++)
        {
            int water = (min(leftMax[i], rightMax[i]) - arr[i]);
            if (water > 0)
                trapWater += water;
        }

        return trapWater;
    }
};

// Using Extreme BruteForce (TLE)

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        // Two Pointer
        int n = arr.size();
        int res = 0;

        for (int i = 1; i < n - 1; i++)
        {
            int leftMax = 0;
            int rightMax = 0;

            for (int j = 0; j < i; j++)
                leftMax = max(leftMax, arr[j]);
            for (int j = i + 1; j < n; j++)
                rightMax = max(rightMax, arr[j]);

            int water = min(leftMax, rightMax) - arr[i];

            if (water > 0)
                res += water;
        }

        return res;
    }
};

// Using Two Pointer Approach

class Solution
{
public:
    int maxWater(vector<int> &arr)
    {
        // Two Pointer
        int n = arr.size();

        int leftMax = arr[0];
        int rightMax = arr[n - 1];

        int i = 1, j = n - 2;
        int trapWater = 0;
        while (i <= j)
        {
            // Case 1 : we have to Calculate at right side
            if (rightMax <= leftMax)
            {
                trapWater += max(0, rightMax - arr[j]);

                rightMax = max(rightMax, arr[j]);

                j--;
            }
            else
            {
                trapWater += max(0, leftMax - arr[i]);

                leftMax = max(leftMax, arr[i]);

                i++;
            }
        }

        return trapWater;
    }
};

int main()
{
    return 0;
}