#include <iostream>
using namespace std;

// Approach 1 : BruteForce
class Solution
{
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr)
    {
        // Your Code Here
        int n = arr.size();

        // Base Case
        if (n == 1)
            return arr[0];

        // OtherWise : BruteForce => O(n * n);
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int temp = 1;
            for (int j = i; j < n; j++)
            {
                temp *= arr[j];
                maxi = max(maxi, temp);
            }
        }

        return maxi;
    }
};

// 2nd Approach

class Solution
{
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr)
    {
        // Your Code Here
        int n = arr.size();

        // Base Case
        if (n == 1)
            return arr[0];

        // OtherWise : Better => O(n)

        int currMin = arr[0];
        int currMax = arr[0];
        int maxProd = arr[0];

        for (int i = 1; i < n; i++)
        {

            int temp = max({arr[i], currMax * arr[i], currMin * arr[i]});

            currMin = min({arr[i], currMax * arr[i], currMin * arr[i]});

            currMax = temp;

            maxProd = max(currMax, maxProd);
        }

        return maxProd;
    }
};

// Approach 3
class Solution
{
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr)
    {
        // Your Code Here
        int n = arr.size();

        int maxProd = INT_MIN;
        int fromLeft = 1;
        int fromRight = 1;

        for (int i = 0; i < n; i++)
        {

            if (fromLeft == 0)
                fromLeft = 1;
            if (fromRight == 0)
                fromRight = 1;

            fromLeft *= arr[i];

            int j = n - i - 1;
            fromRight *= arr[j];

            maxProd = max({maxProd, fromLeft, fromRight});
        }

        return maxProd;
    }
};

int main()
{

    return 0;
}
